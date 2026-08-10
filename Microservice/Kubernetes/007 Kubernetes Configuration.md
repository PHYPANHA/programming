<style>
  body, p, ul, ol, li {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-size: 12pt;
    line-height: 1.6;
  }
  h1, h2, h3, h4, h5, h6 {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-weight: bold;
  }
</style>

# ជំពូកទី ៧៖ ការកំណត់រចនាសម្ព័ន្ធ (Configuration)

នៅក្នុងការអភិវឌ្ឍន៍កម្មវិធី ជារឿយៗយើងត្រូវគ្រប់គ្រង Configuration (ការកំណត់រចនាសម្ព័ន្ធ) ដូចជា Database Connection Strings, API Endpoints, Environment Variables, ឬ Log Levels ។ ការដាក់ Configuration ទាំងនេះដោយផ្ទាល់នៅក្នុង Image របស់ Container អាចបង្កបញ្ហាដូចជាការបង្កើត Image ថ្មីរាល់ពេលដែល Configuration ផ្លាស់ប្តូរ ឬអាចធ្វើឱ្យទិន្នន័យសម្ងាត់ត្រូវបានលាតត្រដាង។

Kubernetes ផ្តល់នូវ Objects ពីរដើម្បីដោះស្រាយបញ្ហានេះ៖ **ConfigMaps** សម្រាប់ទិន្នន័យ Configuration ដែលមិនមែនជាទិន្នន័យសម្ងាត់ និង **Secrets** សម្រាប់ទិន្នន័យសម្ងាត់។

## ៧.១ ConfigMaps (ការគ្រប់គ្រង Configuration ដែលមិនមែនជាទិន្នន័យសម្ងាត់)

### អ្វីទៅជា ConfigMap?

**ConfigMap** គឺជា API Object នៅក្នុង Kubernetes ដែលត្រូវបានប្រើដើម្បីរក្សាទុកទិន្នន័យ Configuration ដែលមិនមែនជាទិន្នន័យសម្ងាត់ (non-confidential data) ជា Key-Value Pairs ។ វាអនុញ្ញាតឱ្យអ្នកបំបែក (decouple) Configuration ចេញពី Image របស់ Container ដែលធ្វើឱ្យ Image កាន់តែអាចប្រើឡើងវិញបាន និងងាយស្រួលក្នុងការគ្រប់គ្រង Configuration ។

### ហេតុអ្វីត្រូវប្រើ ConfigMaps?

*   **បំបែក Configuration ចេញពី Code:** រក្សា Code និង Configuration ដាច់ដោយឡែកពីគ្នា ដែលធ្វើឱ្យការ Update Configuration មិនចាំបាច់បង្កើត Image ថ្មី។
*   **ភាពបត់បែន (Flexibility):** ងាយស្រួលផ្លាស់ប្តូរ Configuration រវាង Environment ផ្សេងៗគ្នា (Dev, Staging, Prod) ។
*   **ការចែករំលែក:** ConfigMaps អាចត្រូវបានប្រើប្រាស់ដោយ Pods ជាច្រើននៅក្នុង Namespace តែមួយ។
*   **ងាយស្រួលប្រើ:** ConfigMaps អាចត្រូវបាន Inject ទៅក្នុង Pods ជា Environment Variables, Command-line Arguments, ឬជា Files នៅក្នុង Volume ។

### របៀបបង្កើត ConfigMap

មានវិធីជាច្រើនដើម្បីបង្កើត ConfigMap ។

#### ១. បង្កើតពី Literal Values (ពី Command Line)
```yaml
# បង្កើត ConfigMap ឈ្មោះ my-config-map ជាមួយ Key-Value Pairs
!kubectl create configmap my-config-map --from-literal=database_host=db-prod --from-literal=database_port=5432
```

#### ២. បង្កើតពី File (ពី Command Line)

អ្នកអាចបង្កើត ConfigMap ពី File មួយ ឬច្រើន។ ឧទាហរណ៍ យើងនឹងបង្កើត File មួយចំនួនជាមុនសិន។

```yaml
%%writefile config1.properties
app_name=MyApp
app_version=1.0.0
```

```yaml
%%writefile config2.env
API_URL=https://api.example.com/v1
LOG_LEVEL=INFO
```

```yaml
# បង្កើត ConfigMap ពី Files ទាំងពីរ
!kubectl create configmap app-config --from-file=config1.properties --from-file=config2.env
```

#### ៣. បង្កើតពី YAML File

អ្នកក៏អាចកំណត់ ConfigMap ដោយផ្ទាល់នៅក្នុង YAML File មួយ។

```yaml
%%writefile my-config-map-yaml.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: my-yaml-config-map
data:
  environment: production
  feature_flags: "true"
  # អ្នកក៏អាចដាក់ Files ពេញលេញនៅទីនេះផងដែរ
  application.properties: |
    server.port=8080
    database.name=production_db
    database.user=admin
```

```yaml
!kubectl apply -f my-config-map-yaml.yaml
```

### ការមើល ConfigMaps

អ្នកអាចមើល ConfigMap ដោយប្រើ `kubectl get` និង `kubectl describe` ។
``` yaml
!kubectl get configmap
!kubectl describe configmap my-config-map
!kubectl describe configmap app-config
!kubectl describe configmap my-yaml-config-map
```

### របៀបប្រើ ConfigMaps នៅក្នុង Pods

ConfigMaps អាចត្រូវបានប្រើប្រាស់នៅក្នុង Pods តាមបីវិធីសំខាន់ៗ៖

#### ១. ជា Environment Variables

```yaml
%%writefile pod-with-configmap-env.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-config-env
spec:
  containers:
  - name: my-app-container
    image: alpine:latest
    command: ["/bin/sh", "-c", "echo DB_HOST=$DB_HOST && echo DB_PORT=$DB_PORT && sleep 3600"]
    env:
    - name: DB_HOST
      valueFrom:
        configMapKeyRef:
          name: my-config-map
          key: database_host
    - name: DB_PORT
      valueFrom:
        configMapKeyRef:
          name: my-config-map
          key: database_port
```

``` yaml
!kubectl apply -f pod-with-configmap-env.yaml
!kubectl get pod pod-with-config-env
!kubectl logs pod-with-config-env
```

#### ២. ជា Files នៅក្នុង Volume

វិធីនេះមានប្រយោជន៍នៅពេលអ្នកមាន Configuration Files ទាំងមូលដែលអ្នកចង់ Mount ទៅក្នុង Pod ។

``` yaml
%%writefile pod-with-configmap-volume.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-config-volume
spec:
  containers:
  - name: my-app-container
    image: alpine:latest
    command: ["/bin/sh", "-c", "cat /etc/config/application.properties && cat /etc/config/feature_flags && sleep 3600"]
    volumeMounts:
    - name: config-volume
      mountPath: /etc/config # Mount ទៅកាន់ Directory នេះ
  volumes:
  - name: config-volume
    configMap:
      name: my-yaml-config-map # ឈ្មោះ ConfigMap ដែលមាន Files
```

``` yaml
!kubectl apply -f pod-with-configmap-volume.yaml
!kubectl get pod pod-with-config-volume
!kubectl logs pod-with-config-volume
```

#### ៣. ជា Command-line Arguments

អ្នកក៏អាចប្រើ ConfigMap Values ជា Arguments សម្រាប់ Container Command បានដែរ។

``` yaml
%%writefile pod-with-configmap-args.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-config-args
spec:
  containers:
  - name: my-app-container
    image: alpine:latest
    command: ["echo"]
    args: ["Environment is $(ENVIRONMENT) with feature flags $(FEATURE_FLAGS)"]
    env:
    - name: ENVIRONMENT
      valueFrom:
        configMapKeyRef:
          name: my-yaml-config-map
          key: environment
    - name: FEATURE_FLAGS
      valueFrom:
        configMapKeyRef:
          name: my-yaml-config-map
          key: feature_flags
```

``` yaml
!kubectl apply -f pod-with-configmap-args.yaml
!kubectl get pod pod-with-config-args
!kubectl logs pod-with-config-args
```

### សរុបមក

ConfigMaps គឺជាវិធីដ៏មានប្រសិទ្ធភាពមួយក្នុងការបំបែក Configuration ចេញពី Image របស់ Container ដែលផ្តល់នូវភាពបត់បែន និងភាពងាយស្រួលក្នុងការគ្រប់គ្រង។ ពួកវាអនុញ្ញាតឱ្យអ្នក Update Configuration ដោយមិនចាំបាច់ Deploy កម្មវិធីឡើងវិញ ហើយអាចត្រូវបានប្រើប្រាស់តាមវិធីជាច្រើននៅក្នុង Pods ។

``` yaml
# Clean up
!kubectl delete configmap my-config-map app-config my-yaml-config-map
!kubectl delete -f pod-with-configmap-env.yaml
!kubectl delete -f pod-with-configmap-volume.yaml
!kubectl delete -f pod-with-configmap-args.yaml
!rm config1.properties config2.env my-config-map-yaml.yaml pod-with-configmap-env.yaml pod-with-configmap-volume.yaml pod-with-configmap-args.yaml
```

## ៧.២ Secrets (ការគ្រប់គ្រងទិន្នន័យសម្ងាត់)

នៅក្នុងការអភិវឌ្ឍន៍កម្មវិធី ជារឿយៗយើងត្រូវការប្រើទិន្នន័យសម្ងាត់ (Sensitive Information) ដូចជា Passwords, API Keys, Database Credentials, ឬ TLS Certificates ។ ការដាក់ទិន្នន័យសម្ងាត់ទាំងនេះដោយផ្ទាល់នៅក្នុង Code, Docker Image, ឬ ConfigMaps អាចបង្កឱ្យមានបញ្ហាសុវត្ថិភាពធ្ងន់ធ្ងរ។

Kubernetes ផ្តល់នូវ API Object មួយឈ្មោះ **Secret** ដើម្បីដោះស្រាយបញ្ហានេះ។

### អ្វីទៅជា Secret?

**Secret** គឺជា Object នៅក្នុង Kubernetes ដែលត្រូវបានប្រើដើម្បីរក្សាទុក និងគ្រប់គ្រងទិន្នន័យសម្ងាត់ ដូចជា Passwords, OAuth Tokens, និង SSH Keys ។ វាផ្តល់នូវវិធីដែលមានសុវត្ថិភាពជាងមុនក្នុងការរក្សាទុកទិន្នន័យសម្ងាត់ជាងការដាក់ពួកវាជា plaintext នៅក្នុង Configuration File ឬ Environment Variable ។

ទិន្នន័យនៅក្នុង Secret ត្រូវបានរក្សាទុកជា Base64-encoded (មិនមែន Encrypted) ។ ដូច្នេះ វាជារឿងសំខាន់ក្នុងការអនុវត្ត Security Best Practices សម្រាប់ Cluster របស់អ្នក ដូចជាការប្រើប្រាស់ RBAC ដើម្បីកំណត់ការចូលប្រើ Secrets និងការប្រើប្រាស់ Encryption at rest សម្រាប់ etcd ។

### ហេតុអ្វីត្រូវប្រើ Secrets?

*   **សុវត្ថិភាព (Security):** ផ្តល់នូវយន្តការជាក់លាក់មួយសម្រាប់រក្សាទុក និងចែកចាយទិន្នន័យសម្ងាត់ ដោយកាត់បន្ថយហានិភ័យនៃការលេចធ្លាយ។
*   **បំបែកទិន្នន័យសម្ងាត់ចេញពី Code:** រក្សាទិន្នន័យសម្ងាត់ដាច់ដោយឡែកពី Code របស់កម្មវិធី។
*   **ភាពបត់បែន (Flexibility):** ងាយស្រួលផ្លាស់ប្តូរទិន្នន័យសម្ងាត់ដោយមិនចាំបាច់ rebuild Images របស់ Container ឬ Restart Pods ទាំងអស់។
*   **ការគ្រប់គ្រង Access:** អាចកំណត់សិទ្ធិចូលប្រើ Secrets ដោយប្រើ RBAC ។

### របៀបបង្កើត Secret

មានវិធីជាច្រើនដើម្បីបង្កើត Secret ។

#### ១. បង្កើតពី Literal Values (ពី Command Line)

``` yaml
# បង្កើត Secret ឈ្មោះ my-db-secret ជាមួយ Key-Value Pairs
!kubectl create secret generic my-db-secret --from-literal=db_username=admin --from-literal=db_password=supersecret
```

#### ២. បង្កើតពី File (ពី Command Line)

អ្នកអាចបង្កើត Secret ពី File មួយ ឬច្រើន។ យើងនឹងបង្កើត File មួយចំនួនជាមុនសិន។

``` yaml
%%writefile username.txt
appuser
```

``` yaml
%%writefile password.txt
apppass123
```

``` yaml
# បង្កើត Secret ពី Files ទាំងពីរ
!kubectl create secret generic app-credentials --from-file=username.txt --from-file=password.txt
```

#### ៣. បង្កើតពី YAML File

អ្នកក៏អាចកំណត់ Secret ដោយផ្ទាល់នៅក្នុង YAML File មួយ។ ទិន្នន័យត្រូវតែជា Base64-encoded ។

**ចំណាំ:** អ្នកអាចប្រើ `echo -n 'your_value' | base64` ដើម្បី Convert Text ទៅជា Base64 ។

``` yaml
# ឧទាហរណ៍: echo -n 'my-tls-cert' | base64  => bXktdGxzLWNlcnQ=
# ឧទាហរណ៍: echo -n 'my-tls-key' | base64   => bXktdGxzLWtleQ=
%%writefile my-tls-secret.yaml
apiVersion: v1
kind: Secret
metadata:
  name: my-tls-secret
type: Opaque
data:
  tls.crt: bXktdGxzLWNlcnQ=
  tls.key: bXktdGxzLWtleQ=
```

``` yaml
!kubectl apply -f my-tls-secret.yaml
```

### ការមើល Secrets

អ្នកអាចមើល Secret ដោយប្រើ `kubectl get` និង `kubectl describe` ។

``` yaml
!kubectl get secret
!kubectl describe secret my-db-secret
!kubectl describe secret app-credentials
!kubectl describe secret my-tls-secret
```

**ចំណាំ:** នៅពេលអ្នក `describe` Secret ទិន្នន័យ (Data) នឹងត្រូវបានបង្ហាញជាចំនួន Bytes មិនមែនជា Plain Text នោះទេ។ ដើម្បីមើលទិន្នន័យ Plain Text អ្នកត្រូវប្រើ `kubectl get secret <name> -o yaml` ហើយបន្ទាប់មក Decode ទិន្នន័យ Base64 ។

``` yaml
# មើលទិន្នន័យ Base64 របស់ Secret
!kubectl get secret my-db-secret -o yaml

# ឧទាហរណ៍: Decode Base64 value manually (replace 'YWRtaW4=' with the actual base64 string from the output)
# echo 'YWRtaW4=' | base64 --decode
```

### របៀបប្រើ Secrets នៅក្នុង Pods

Secrets អាចត្រូវបានប្រើប្រាស់នៅក្នុង Pods តាមពីរវិធីសំខាន់ៗ៖

#### ១. ជា Environment Variables

``` yaml
%%writefile pod-with-secret-env.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-secret-env
spec:
  containers:
  - name: my-app-container
    image: alpine:latest
    command: ["/bin/sh", "-c", "echo DB_USERNAME=$DB_USERNAME && echo DB_PASSWORD=$DB_PASSWORD && sleep 3600"]
    env:
    - name: DB_USERNAME
      valueFrom:
        secretKeyRef:
          name: my-db-secret # ឈ្មោះ Secret
          key: db_username   # Key នៅក្នុង Secret
    - name: DB_PASSWORD
      valueFrom:
        secretKeyRef:
          name: my-db-secret # ឈ្មោះ Secret
          key: db_password   # Key នៅក្នុង Secret
```

``` yaml
!kubectl apply -f pod-with-secret-env.yaml
!kubectl get pod pod-with-secret-env
!kubectl logs pod-with-secret-env
```

#### ២. ជា Files នៅក្នុង Volume

វិធីនេះមានប្រយោជន៍នៅពេលអ្នកមាន Credentials (ឧទាហរណ៍ TLS Certificates) ឬ Files ទាំងមូលដែលអ្នកចង់ Mount ទៅក្នុង Pod ។

``` yaml
%%writefile pod-with-secret-volume.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-secret-volume
spec:
  containers:
  - name: my-app-container
    image: alpine:latest
    command: ["/bin/sh", "-c", "cat /etc/certs/tls.crt && cat /etc/certs/tls.key && sleep 3600"]
    volumeMounts:
    - name: tls-volume
      mountPath: /etc/certs # Mount ទៅកាន់ Directory នេះ
      readOnly: true      # គួរតែកំណត់ជា Read-Only សម្រាប់ Security
  volumes:
  - name: tls-volume
    secret:
      secretName: my-tls-secret # ឈ្មោះ Secret ដែលមាន Files
```

``` yaml
!kubectl apply -f pod-with-secret-volume.yaml
!kubectl get pod pod-with-secret-volume
!kubectl logs pod-with-secret-volume
```

### សរុបមក

Secrets គឺជា Object ដ៏សំខាន់សម្រាប់រក្សាទុក និងគ្រប់គ្រងទិន្នន័យសម្ងាត់នៅក្នុង Kubernetes ។ ពួកវាជួយបង្កើនសុវត្ថិភាពរបស់កម្មវិធីរបស់អ្នកដោយបំបែក Sensitive Data ចេញពី Code និង Configuration ធម្មតា។ ការយល់ដឹងពីរបៀបប្រើ Secrets ឱ្យបានត្រឹមត្រូវគឺចាំបាច់សម្រាប់ Deploy កម្មវិធីដែលមានសុវត្ថិភាពនៅក្នុង Kubernetes ។

``` yaml
# Clean up
!kubectl delete secret my-db-secret app-credentials my-tls-secret
!kubectl delete -f pod-with-secret-env.yaml
!kubectl delete -f pod-with-secret-volume.yaml
!rm username.txt password.txt my-tls-secret.yaml pod-with-secret-env.yaml pod-with-secret-volume.yaml
```

## ៧.៣ Service Accounts (ការគ្រប់គ្រងសិទ្ធិរបស់ Pods)

នៅក្នុង Kubernetes Pod នីមួយៗដែលដំណើរការនៅក្នុង Cluster ត្រូវការអត្តសញ្ញាណ (identity) ដើម្បីអាចទំនាក់ទំនងជាមួយ Kubernetes API Server បាន។ ឧទាហរណ៍ Pod មួយអាចត្រូវការអាន ConfigMaps ឬបង្កើត Deployments ។ អត្តសញ្ញាណនេះត្រូវបានផ្តល់ដោយ **Service Account** ។

### អ្វីទៅជា Service Account?

**Service Account** គឺជា Object នៅក្នុង Kubernetes ដែលផ្តល់នូវអត្តសញ្ញាណសម្រាប់ Processes ដែលដំណើរការនៅក្នុង Pods ។ វាមានលក្ខណៈស្រដៀងនឹង User Account ប៉ុន្តែសម្រាប់ Pods/Applications ជំនួសឱ្យ Users ។

Kubernetes Cluster នីមួយៗមាន Service Account លំនាំដើមមួយឈ្មោះ `default` នៅក្នុង Namespace នីមួយៗ។ ប្រសិនបើអ្នកមិនបានបញ្ជាក់ Service Account សម្រាប់ Pod ទេ Pod នោះនឹងប្រើ `default` Service Account របស់ Namespace របស់វា។

### ហេតុអ្វីត្រូវប្រើ Service Accounts?

*   **ការគ្រប់គ្រង Access របស់ Pods (Access Control):** Service Account ត្រូវបានភ្ជាប់ជាមួយ Role-Based Access Control (RBAC) ដើម្បីកំណត់ថា Pod មួយណាមានសិទ្ធិអ្វីខ្លះនៅក្នុង Cluster ។
*   **គោលការណ៍ Security (Security Policies):** ជួយអនុវត្តគោលការណ៍ Security ដោយផ្តល់ឱ្យ Pod នីមួយៗនូវសិទ្ធិអប្បបរមាដែលវាត្រូវការ (Principle of Least Privilege) ។
*   **បំបែកសិទ្ធិ:** កម្មវិធីផ្សេងៗគ្នាអាចមាន Service Account រៀងៗខ្លួនជាមួយនឹងសិទ្ធិខុសៗគ្នា។

### របៀបដែល Service Accounts ដំណើរការ

នៅពេល Pod មួយត្រូវបានបង្កើត ហើយវាត្រូវបានភ្ជាប់ជាមួយ Service Account (ទាំង `default` ឬមួយដែលអ្នកបានបង្កើត) Kubernetes នឹងធ្វើការងារបីយ៉ាង:

1.  **Mount Token:** Kubernetes នឹង Inject Secret (Token) ដែលមាន Credentials សម្រាប់ Service Account នោះទៅកាន់ Pod នៅ Path `/var/run/secrets/kubernetes.io/serviceaccount/token` ។
2.  **Mount CA Certificate:** វានឹង Mount CA Certificate របស់ Cluster នៅ Path `/var/run/secrets/kubernetes.io/serviceaccount/ca.crt` ។
3.  **Configure DNS:** វានឹងកំណត់រចនាសម្ព័ន្ធ DNS សម្រាប់ Pod ដើម្បីឱ្យវាអាចស្វែងរក Kubernetes API Server ។

Processes នៅក្នុង Container អាចប្រើ Token នេះដើម្បី Authenticate ខ្លួនឯងទៅកាន់ Kubernetes API Server ។

### របៀបបង្កើត Service Account

#### ១. បង្កើត Service Account ធម្មតា

**ឧទាហរណ៍ Service Account YAML (my-app-sa.yaml):**

``` yaml
%%writefile my-app-sa.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: my-app-service-account
  namespace: default # Service Account នេះស្ថិតនៅក្នុង Namespace default
```

``` yaml
!kubectl apply -f my-app-sa.yaml
```

#### ២. មើល Service Accounts

អ្នកអាចមើល Service Account ដែលបានបង្កើតរួច៖

``` yaml
!kubectl get serviceaccount
!kubectl describe serviceaccount my-app-service-account
```

អ្នកនឹងឃើញថា Service Account នីមួយៗ (រួមទាំង `default` និង `my-app-service-account` ដែលយើងបានបង្កើត) មាន Token Secret ដែលត្រូវបានភ្ជាប់ជាមួយវាដោយស្វ័យប្រវត្តិ។

### របៀបប្រើ Service Account នៅក្នុង Pods

ដើម្បីប្រើ Service Account នៅក្នុង Pod អ្នកគ្រាន់តែបញ្ជាក់ `serviceAccountName` នៅក្នុង Pod Specification ។

#### ឧទាហរណ៍ Pod ដែលប្រើ Service Account

យើងនឹងបង្កើត Pod មួយដែលព្យាយាមអាន Deployments នៅក្នុង Cluster ។ ប្រសិនបើវាមិនមានសិទ្ធិទេ វានឹងបរាជ័យ។ បន្ទាប់មកយើងនឹងផ្តល់សិទ្ធិឱ្យ Service Account របស់វា។

``` yaml
%%writefile pod-with-custom-sa.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-api-reader-pod
spec:
  serviceAccountName: my-app-service-account # កំណត់ Service Account សម្រាប់ Pod នេះ
  containers:
  - name: api-reader
    image: bitnami/kubectl:latest # Image ដែលមាន kubectl CLI
    command: ["/bin/bash", "-c"]
    args: ["echo 'Attempting to get deployments...' && kubectl get deployments && sleep 3600"]
  restartPolicy: Never
```

``` yaml
!kubectl apply -f pod-with-custom-sa.yaml
```

ឥឡូវនេះ សូមពិនិត្យមើល Logs របស់ Pod នេះ។

``` yaml
!kubectl logs my-api-reader-pod
```

អ្នកនឹងឃើញ Error ដែលបញ្ជាក់ថា Service Account `system:serviceaccount:default:my-app-service-account` មិនមានសិទ្ធិ `get` នៅលើ `deployments.apps` នោះទេ។ នេះដោយសារតែ Service Account ថ្មីដែលយើងបង្កើតគឺមិនមានសិទ្ធិអ្វីទាំងអស់តាម Default ។

### ការផ្តល់សិទ្ធិដល់ Service Account (ដោយប្រើ RBAC)

ដើម្បីផ្តល់សិទ្ធិឱ្យ Service Account យើងត្រូវប្រើ Role-Based Access Control (RBAC) ។ យើងនឹងបង្កើត `Role` និង `RoleBinding` ។

*   **`Role`:** កំណត់សំណុំនៃ Permissions (សិទ្ធិ) ។
*   **`RoleBinding`:** ភ្ជាប់ `Role` ទៅកាន់ `Service Account` (ឬ User/Group) នៅក្នុង Namespace ជាក់លាក់មួយ។

``` yaml
%%writefile deployment-reader-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: deployment-reader
  namespace: default
rules:
- apiGroups: ["apps"] # កំណត់ API Group ដែល Role នេះមានសិទ្ធិ
  resources: ["deployments"] # កំណត់ Resource ដែល Role នេះមានសិទ្ធិ
  verbs: ["get", "list"] # កំណត់ប្រភេទសិទ្ធិ (get, list, watch, create, update, delete)
```

``` yaml
%%writefile deployment-reader-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: read-deployments
  namespace: default
subjects:
- kind: ServiceAccount
  name: my-app-service-account # ឈ្មោះ Service Account ដែលត្រូវផ្តល់សិទ្ធិ
  namespace: default
roleRef:
  kind: Role
  name: deployment-reader # ឈ្មោះ Role ដែលត្រូវភ្ជាប់
  apiGroup: rbac.authorization.k8s.io
```

``` yaml
!kubectl apply -f deployment-reader-role.yaml
!kubectl apply -f deployment-reader-rolebinding.yaml
```

ឥឡូវនេះ Service Account `my-app-service-account` ត្រូវបានផ្តល់សិទ្ធិឱ្យ `get` និង `list` Deployments នៅក្នុង Namespace `default` ។

#### ព្យាយាមម្តងទៀត (បន្ទាប់ពីផ្តល់សិទ្ធិ)

យើងនឹងលុប Pod ចាស់ចោល ហើយបង្កើតវាឡើងវិញ ដើម្បីឱ្យវាប្រើ Service Account ជាមួយនឹងសិទ្ធិថ្មី។

``` yaml
!kubectl delete -f pod-with-custom-sa.yaml
!kubectl apply -f pod-with-custom-sa.yaml
```

បន្ទាប់ពី Pod ដំណើរការ សូមពិនិត្យមើល Logs ម្តងទៀត៖

``` yaml
!kubectl logs my-api-reader-pod
```

អ្នកគួរតែឃើញ Output នៃ `kubectl get deployments` ដែលបង្ហាញថា Pod ឥឡូវនេះមានសិទ្ធិចូលប្រើ Kubernetes API បានត្រឹមត្រូវ។

### សរុបមក

Service Accounts គឺជាយន្តការដ៏សំខាន់មួយនៅក្នុង Kubernetes សម្រាប់គ្រប់គ្រងអត្តសញ្ញាណ និងសិទ្ធិចូលប្រើរបស់កម្មវិធីដែលដំណើរការនៅក្នុង Pods ។ តាមរយៈការប្រើប្រាស់ Service Accounts រួមជាមួយ RBAC (Roles និង RoleBindings) អ្នកអាចធានាថា Pod នីមួយៗមានសិទ្ធិត្រឹមត្រូវតាមតម្រូវការរបស់វា ដែលជួយបង្កើនសុវត្ថិភាព និងការគ្រប់គ្រងនៅក្នុង Cluster របស់អ្នក។

## ៧.៤ SecurityContext (សុវត្ថិភាព Pod និង Container)

នៅក្នុងបរិយាកាស Containerized ការកំណត់រចនាសម្ព័ន្ធសុវត្ថិភាពសម្រាប់ Pods និង Containers របស់អ្នកគឺមានសារៈសំខាន់ណាស់ ដើម្បីការពារពីការគំរាមកំហែង និងធានានូវគោលការណ៍ **Least Privilege** (ផ្តល់សិទ្ធិអប្បបរមា)។ Kubernetes ផ្តល់នូវ **SecurityContext** ដើម្បីអនុញ្ញាតឱ្យអ្នកកំណត់ការកំណត់សុវត្ថិភាពទាំងនេះ។

### អ្វីទៅជា SecurityContext?

**SecurityContext** គឺជា Field នៅក្នុង Pod និង Container Definition ដែលអនុញ្ញាតឱ្យអ្នកកំណត់ Privilege (សិទ្ធិ) និង Access Control Settings (ការគ្រប់គ្រងការចូលប្រើ) សម្រាប់ Pods ឬ Containers ។ ការកំណត់ទាំងនេះប៉ះពាល់ដល់ User ID (UID), Group ID (GID), Linux Capabilities, SELinux Contexts, AppArmor Profiles, និង Seccomp Profiles ។

**SecurityContext អាចត្រូវបានកំណត់នៅពីរទីតាំង:**

1.  **`pod.spec.securityContext`:** កំណត់ការកំណត់សុវត្ថិភាពសម្រាប់ Pod ទាំងមូល។ ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Containers ទាំងអស់នៅក្នុង Pod និង Volumes មួយចំនួន។
2.  **`pod.spec.containers[].securityContext`:** កំណត់ការកំណត់សុវត្ថិភាពសម្រាប់ Container ជាក់លាក់មួយ។ ការកំណត់ទាំងនេះនឹង override (បដិសេធ) ការកំណត់ដែលបានបញ្ជាក់នៅកម្រិត Pod (ប្រសិនបើមានការកំណត់ដូចគ្នា)។

### ហេតុអ្វីត្រូវប្រើ SecurityContext?

*   **កាត់បន្ថយហានិភ័យសុវត្ថិភាព:** ការដំណើរការ Containers ជា User ដែលមិនមែនជា Root User (non-root user) និងកំណត់ Linux Capabilities អាចកាត់បន្ថយហានិភ័យនៃការកេងប្រវ័ញ្ច។
*   **អនុវត្តគោលការណ៍ Least Privilege:** ធានាថាកម្មវិធីរបស់អ្នកមានសិទ្ធិចាំបាច់សម្រាប់ដំណើរការតែប៉ុណ្ណោះ។
*   **ភាពស៊ីគ្នា:** ធានាថា Containers របស់អ្នកដំណើរការក្នុងបរិយាកាសដែលមានសុវត្ថិភាពដូចគ្នា។

### ការកំណត់ SecurityContext ទូទៅ

យើងនឹងស្វែងយល់ពីការកំណត់ទូទៅមួយចំនួនដែលត្រូវបានប្រើប្រាស់នៅកម្រិត Pod និង Container ។

#### ១. នៅកម្រិត Pod (pod.spec.securityContext)

ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Containers ទាំងអស់នៅក្នុង Pod និង Volumes មួយចំនួន។

*   **`runAsUser` / `runAsGroup`:** កំណត់ UID / GID ដែល Container របស់ Pod នឹងដំណើរការ។
*   **`fsGroup`:** កំណត់ Group ID សម្រាប់ Persistent Volumes ដែល Mount ទៅក្នុង Pod ។ Files និង Directories នៅក្នុង Volume ទាំងនោះនឹងជាកម្មសិទ្ធិរបស់ Group ID នេះ។

``` yaml
%%writefile pod-security-context.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-secure-pod
spec:
  securityContext: # កំណត់នៅកម្រិត Pod
    runAsUser: 1000       # កំណត់ UID 1000 សម្រាប់ Processes ទាំងអស់នៅក្នុង Container
    runAsGroup: 3000      # កំណត់ GID 3000 សម្រាប់ Processes ទាំងអស់នៅក្នុង Container
    fsGroup: 2000         # កំណត់ GID 2000 សម្រាប់ Volume Filesystems
  containers:
  - name: my-container
    image: alpine:latest
    command: ["sh", "-c", "id && ls -ld /data && sleep 3600"]
    volumeMounts:
    - name: my-volume
      mountPath: /data
  volumes:
  - name: my-volume
    emptyDir: {}
```

``` yaml
!kubectl apply -f pod-security-context.yaml
!kubectl get pod my-secure-pod
!kubectl wait --for=condition=Ready pod/my-secure-pod --timeout=60s
!kubectl logs my-secure-pod
```

**ការពន្យល់:**

*   `id` command នៅក្នុង Log Output បង្ហាញ `uid=1000(nonrootuser) gid=3000(nonrootgroup) groups=3000(nonrootgroup)` (ឈ្មោះ user/group អាចប្រែប្រួលតាម image)។
*   `ls -ld /data` command បង្ហាញថា Directory `/data` (ដែលជា Volume) មាន `gid=2000` ដែលបានកំណត់ដោយ `fsGroup` ។

#### ២. នៅកម្រិត Container (pod.spec.containers[].securityContext)

ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Container ជាក់លាក់មួយ។

*   **`runAsNonRoot`:** ប្រសិនបើកំណត់ជា `true` Container នឹងបដិសេធមិនដំណើរការជា `root` (UID 0) ទេ។
*   **`readOnlyRootFilesystem`:** ប្រសិនបើកំណត់ជា `true` Filesystem របស់ Container នឹងត្រូវបាន Mount ជា Read-Only ដែលជួយបង្កើនសុវត្ថិភាព។
*   **`allowPrivilegeEscalation`:** កំណត់ថាតើដំណើរការនៅក្នុង Container អាចទទួលបាន Privilege លើសពី Parent Process របស់វាដែរឬទេ។
*   **`capabilities`:** អនុញ្ញាតឱ្យអ្នកបន្ថែម (add) ឬលុប (drop) Linux Capabilities សម្រាប់ Container ។
    *   `DROP_ALL` គឺជាការអនុវត្តដ៏ល្អបំផុតដើម្បីលុប Capabilities ទាំងអស់ដែលមិនចាំបាច់។
    *   `NET_BIND_SERVICE` អនុញ្ញាតឱ្យ Processes Bind Ports តូចជាង 1024 ។

``` yaml
%%writefile container-security-context.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-secure-container-pod
spec:
  containers:
  - name: my-app-container
    image: nginx:latest
    securityContext: # កំណត់នៅកម្រិត Container
      runAsNonRoot: true         # បដិសេធមិនដំណើរការជា root
      runAsUser: 1001            # កំណត់ UID 1001
      readOnlyRootFilesystem: true # Root Filesystem របស់ Container គឺ Read-Only
      allowPrivilegeEscalation: false # មិនអនុញ្ញាតឱ្យបង្កើន Privilege
      capabilities:
        drop:
          - ALL                 # លុប Capabilities ទាំងអស់
        add:
          - NET_BIND_SERVICE  # បន្ថែម Capability សម្រាប់ Bind Port < 1024 (បើចាំបាច់)
    ports:
    - containerPort: 80 # Nginx ត្រូវការ Bind Port 80
    # ត្រូវ Mount Volume សម្រាប់ Nginx Web Root ប្រសិនបើ readOnlyRootFilesystem គឺ true
    volumeMounts:
    - name: nginx-html
      mountPath: /etc/nginx/conf.d
      readOnly: true
    - name: nginx-html-root
      mountPath: /usr/share/nginx/html
  volumes:
  - name: nginx-html
    emptyDir: {}
  - name: nginx-html-root
    emptyDir: {}
```

``` yaml
!kubectl apply -f container-security-context.yaml
!kubectl get pod my-secure-container-pod
!kubectl wait --for=condition=Ready pod/my-secure-container-pod --timeout=60s
!kubectl describe pod my-secure-container-pod
```

**ការពន្យល់:**

*   នៅក្នុង `describe` output អ្នកនឹងឃើញ `Security Context:` សម្រាប់ Container ដែលបង្ហាញពីការកំណត់ទាំងនេះ។
*   Pod នេះនឹងដំណើរការ Nginx ជា User ID `1001` ហើយ Root Filesystem របស់វាគឺ Read-Only ។

### សរុបមក

**SecurityContext** គឺជាឧបករណ៍ដ៏មានអានុភាពនៅក្នុង Kubernetes សម្រាប់អនុវត្តគោលការណ៍សុវត្ថិភាពនៅកម្រិត Pod និង Container ។ ការកំណត់ `runAsUser`, `runAsGroup`, `fsGroup`, `runAsNonRoot`, `readOnlyRootFilesystem`, និង `capabilities` ជួយកាត់បន្ថយ Surface Area នៃការវាយប្រហារ និងធានាថាកម្មវិធីរបស់អ្នកដំណើរការជាមួយនឹងសិទ្ធិចាំបាច់តែប៉ុណ្ណោះ។ ការអនុវត្ត SecurityContext គឺជាផ្នែកសំខាន់មួយនៃការ Deploy កម្មវិធីដែលមានសុវត្ថិភាពនៅក្នុង Kubernetes Cluster ។

``` yaml
# Clean up
!kubectl delete -f pod-security-context.yaml
!kubectl delete -f container-security-context.yaml
!rm pod-security-context.yaml container-security-context.yaml
```
``` yaml
# Clean up
!kubectl delete -f my-app-sa.yaml
!kubectl delete -f pod-with-custom-sa.yaml
!kubectl delete -f deployment-reader-role.yaml
!kubectl delete -f deployment-reader-rolebinding.yaml
!rm my-app-sa.yaml pod-with-custom-sa.yaml deployment-reader-role.yaml deployment-reader-rolebinding.yaml
```

នៅក្នុង Kubernetes Pod នីមួយៗដែលដំណើរការនៅក្នុង Cluster ត្រូវការអត្តសញ្ញាណ (identity) ដើម្បីអាចទំនាក់ទំនងជាមួយ Kubernetes API Server បាន។ ឧទាហរណ៍ Pod មួយអាចត្រូវការអាន ConfigMaps ឬបង្កើត Deployments ។ អត្តសញ្ញាណនេះត្រូវបានផ្តល់ដោយ **Service Account** ។

### អ្វីទៅជា Service Account?

**Service Account** គឺជា Object នៅក្នុង Kubernetes ដែលផ្តល់នូវអត្តសញ្ញាណសម្រាប់ Processes ដែលដំណើរការនៅក្នុង Pods ។ វាមានលក្ខណៈស្រដៀងនឹង User Account ប៉ុន្តែសម្រាប់ Pods/Applications ជំនួសឱ្យ Users ។

Kubernetes Cluster នីមួយៗមាន Service Account លំនាំដើមមួយឈ្មោះ `default` នៅក្នុង Namespace នីមួយៗ។ ប្រសិនបើអ្នកមិនបានបញ្ជាក់ Service Account សម្រាប់ Pod ទេ Pod នោះនឹងប្រើ `default` Service Account របស់ Namespace របស់វា។

### ហេតុអ្វីត្រូវប្រើ Service Accounts?

*   **ការគ្រប់គ្រង Access របស់ Pods (Access Control):** Service Account ត្រូវបានភ្ជាប់ជាមួយ Role-Based Access Control (RBAC) ដើម្បីកំណត់ថា Pod មួយណាមានសិទ្ធិអ្វីខ្លះនៅក្នុង Cluster ។
*   **គោលការណ៍ Security (Security Policies):** ជួយអនុវត្តគោលការណ៍ Security ដោយផ្តល់ឱ្យ Pod នីមួយៗនូវសិទ្ធិអប្បបរមាដែលវាត្រូវការ (Principle of Least Privilege) ។
*   **បំបែកសិទ្ធិ:** កម្មវិធីផ្សេងៗគ្នាអាចមាន Service Account រៀងៗខ្លួនជាមួយនឹងសិទ្ធិខុសៗគ្នា។

### របៀបដែល Service Accounts ដំណើរការ

នៅពេល Pod មួយត្រូវបានបង្កើត ហើយវាត្រូវបានភ្ជាប់ជាមួយ Service Account (ទាំង `default` ឬមួយដែលអ្នកបានបង្កើត) Kubernetes នឹងធ្វើការងារបីយ៉ាង:

1.  **Mount Token:** Kubernetes នឹង Inject Secret (Token) ដែលមាន Credentials សម្រាប់ Service Account នោះទៅកាន់ Pod នៅ Path `/var/run/secrets/kubernetes.io/serviceaccount/token` ។
2.  **Mount CA Certificate:** វានឹង Mount CA Certificate របស់ Cluster នៅ Path `/var/run/secrets/kubernetes.io/serviceaccount/ca.crt` ។
3.  **Configure DNS:** វានឹងកំណត់រចនាសម្ព័ន្ធ DNS សម្រាប់ Pod ដើម្បីឱ្យវាអាចស្វែងរក Kubernetes API Server ។

Processes នៅក្នុង Container អាចប្រើ Token នេះដើម្បី Authenticate ខ្លួនឯងទៅកាន់ Kubernetes API Server ។

### របៀបបង្កើត Service Account

#### ១. បង្កើត Service Account ធម្មតា

**ឧទាហរណ៍ Service Account YAML (my-app-sa.yaml):**

``` yaml
%%writefile my-app-sa.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: my-app-service-account
  namespace: default # Service Account នេះស្ថិតនៅក្នុង Namespace default
```
``` yaml
!kubectl apply -f my-app-sa.yaml
```

#### ២. មើល Service Accounts

អ្នកអាចមើល Service Account ដែលបានបង្កើតរួច៖

``` yaml
!kubectl get serviceaccount
!kubectl describe serviceaccount my-app-service-account
```

អ្នកនឹងឃើញថា Service Account នីមួយៗ (រួមទាំង `default` និង `my-app-service-account` ដែលយើងបានបង្កើត) មាន Token Secret ដែលត្រូវបានភ្ជាប់ជាមួយវាដោយស្វ័យប្រវត្តិ។

### របៀបប្រើ Service Account នៅក្នុង Pods

ដើម្បីប្រើ Service Account នៅក្នុង Pod អ្នកគ្រាន់តែបញ្ជាក់ `serviceAccountName` នៅក្នុង Pod Specification ។

#### ឧទាហរណ៍ Pod ដែលប្រើ Service Account

យើងនឹងបង្កើត Pod មួយដែលព្យាយាមអាន Deployments នៅក្នុង Cluster ។ ប្រសិនបើវាមិនមានសិទ្ធិទេ វានឹងបរាជ័យ។ បន្ទាប់មកយើងនឹងផ្តល់សិទ្ធិឱ្យ Service Account របស់វា។

``` yaml
%%writefile pod-with-custom-sa.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-api-reader-pod
spec:
  serviceAccountName: my-app-service-account # កំណត់ Service Account សម្រាប់ Pod នេះ
  containers:
  - name: api-reader
    image: bitnami/kubectl:latest # Image ដែលមាន kubectl CLI
    command: ["/bin/bash", "-c"]
    args: ["echo 'Attempting to get deployments...' && kubectl get deployments && sleep 3600"]
  restartPolicy: Never
```

``` yaml
!kubectl apply -f pod-with-custom-sa.yaml
```

ឥឡូវនេះ សូមពិនិត្យមើល Logs របស់ Pod នេះ។

``` yaml
!kubectl logs my-api-reader-pod
```

អ្នកនឹងឃើញ Error ដែលបញ្ជាក់ថា Service Account `system:serviceaccount:default:my-app-service-account` មិនមានសិទ្ធិ `get` នៅលើ `deployments.apps` នោះទេ។ នេះដោយសារតែ Service Account ថ្មីដែលយើងបង្កើតគឺមិនមានសិទ្ធិអ្វីទាំងអស់តាម Default ។

### ការផ្តល់សិទ្ធិដល់ Service Account (ដោយប្រើ RBAC)

ដើម្បីផ្តល់សិទ្ធិឱ្យ Service Account យើងត្រូវប្រើ Role-Based Access Control (RBAC) ។ យើងនឹងបង្កើត `Role` និង `RoleBinding` ។

*   **`Role`:** កំណត់សំណុំនៃ Permissions (សិទ្ធិ) ។
*   **`RoleBinding`:** ភ្ជាប់ `Role` ទៅកាន់ `Service Account` (ឬ User/Group) នៅក្នុង Namespace ជាក់លាក់មួយ។

``` yaml
%%writefile deployment-reader-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: deployment-reader
  namespace: default
rules:
- apiGroups: ["apps"] # កំណត់ API Group ដែល Role នេះមានសិទ្ធិ
  resources: ["deployments"] # កំណត់ Resource ដែល Role នេះមានសិទ្ធិ
  verbs: ["get", "list"] # កំណត់ប្រភេទសិទ្ធិ (get, list, watch, create, update, delete)
```

``` yaml
%%writefile deployment-reader-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: read-deployments
  namespace: default
subjects:
- kind: ServiceAccount
  name: my-app-service-account # ឈ្មោះ Service Account ដែលត្រូវផ្តល់សិទ្ធិ
  namespace: default
roleRef:
  kind: Role
  name: deployment-reader # ឈ្មោះ Role ដែលត្រូវភ្ជាប់
  apiGroup: rbac.authorization.k8s.io
```

``` yaml
!kubectl apply -f deployment-reader-role.yaml
!kubectl apply -f deployment-reader-rolebinding.yaml
```

ឥឡូវនេះ Service Account `my-app-service-account` ត្រូវបានផ្តល់សិទ្ធិឱ្យ `get` និង `list` Deployments នៅក្នុង Namespace `default` ។

#### ព្យាយាមម្តងទៀត (បន្ទាប់ពីផ្តល់សិទ្ធិ)

យើងនឹងលុប Pod ចាស់ចោល ហើយបង្កើតវាឡើងវិញ ដើម្បីឱ្យវាប្រើ Service Account ជាមួយនឹងសិទ្ធិថ្មី។

``` yaml
!kubectl delete -f pod-with-custom-sa.yaml
!kubectl apply -f pod-with-custom-sa.yaml
```

បន្ទាប់ពី Pod ដំណើរការ សូមពិនិត្យមើល Logs ម្តងទៀត៖

``` yaml
!kubectl logs my-api-reader-pod
```

អ្នកគួរតែឃើញ Output នៃ `kubectl get deployments` ដែលបង្ហាញថា Pod ឥឡូវនេះមានសិទ្ធិចូលប្រើ Kubernetes API បានត្រឹមត្រូវ។

### សរុបមក

Service Accounts គឺជាយន្តការដ៏សំខាន់មួយនៅក្នុង Kubernetes សម្រាប់គ្រប់គ្រងអត្តសញ្ញាណ និងសិទ្ធិចូលប្រើរបស់កម្មវិធីដែលដំណើរការនៅក្នុង Pods ។ តាមរយៈការប្រើប្រាស់ Service Accounts រួមជាមួយ RBAC (Roles និង RoleBindings) អ្នកអាចធានាថា Pod នីមួយៗមានសិទ្ធិត្រឹមត្រូវតាមតម្រូវការរបស់វា ដែលជួយបង្កើនសុវត្ថិភាព និងការគ្រប់គ្រងនៅក្នុង Cluster របស់អ្នក។

``` yaml
# Clean up
!kubectl delete -f my-app-sa.yaml
!kubectl delete -f pod-with-custom-sa.yaml
!kubectl delete -f deployment-reader-role.yaml
!kubectl delete -f deployment-reader-rolebinding.yaml
!rm my-app-sa.yaml pod-with-custom-sa.yaml deployment-reader-role.yaml deployment-reader-rolebinding.yaml
```

## ៧.៤ SecurityContext (សុវត្ថិភាព Pod និង Container)

នៅក្នុងបរិយាកាស Containerized ការកំណត់រចនាសម្ព័ន្ធសុវត្ថិភាពសម្រាប់ Pods និង Containers របស់អ្នកគឺមានសារៈសំខាន់ណាស់ ដើម្បីការពារពីការគំរាមកំហែង និងធានានូវគោលការណ៍ **Least Privilege** (ផ្តល់សិទ្ធិអប្បបរមា)។ Kubernetes ផ្តល់នូវ **SecurityContext** ដើម្បីអនុញ្ញាតឱ្យអ្នកកំណត់ការកំណត់សុវត្ថិភាពទាំងនេះ។

### អ្វីទៅជា SecurityContext?

**SecurityContext** គឺជា Field នៅក្នុង Pod និង Container Definition ដែលអនុញ្ញាតឱ្យអ្នកកំណត់ Privilege (សិទ្ធិ) និង Access Control Settings (ការគ្រប់គ្រងការចូលប្រើ) សម្រាប់ Pods ឬ Containers ។ ការកំណត់ទាំងនេះប៉ះពាល់ដល់ User ID (UID), Group ID (GID), Linux Capabilities, SELinux Contexts, AppArmor Profiles, និង Seccomp Profiles ។

**SecurityContext អាចត្រូវបានកំណត់នៅពីរទីតាំង:**

1.  **`pod.spec.securityContext`:** កំណត់ការកំណត់សុវត្ថិភាពសម្រាប់ Pod ទាំងមូល។ ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Containers ទាំងអស់នៅក្នុង Pod និង Volumes មួយចំនួន។
2.  **`pod.spec.containers[].securityContext`:** កំណត់ការកំណត់សុវត្ថិភាពសម្រាប់ Container ជាក់លាក់មួយ។ ការកំណត់ទាំងនេះនឹង override (បដិសេធ) ការកំណត់ដែលបានបញ្ជាក់នៅកម្រិត Pod (ប្រសិនបើមានការកំណត់ដូចគ្នា)។

### ហេតុអ្វីត្រូវប្រើ SecurityContext?

*   **កាត់បន្ថយហានិភ័យសុវត្ថិភាព:** ការដំណើរការ Containers ជា User ដែលមិនមែនជា Root User (non-root user) និងកំណត់ Linux Capabilities អាចកាត់បន្ថយហានិភ័យនៃការកេងប្រវ័ញ្ច។
*   **អនុវត្តគោលការណ៍ Least Privilege:** ធានាថាកម្មវិធីរបស់អ្នកមានសិទ្ធិចាំបាច់សម្រាប់ដំណើរការតែប៉ុណ្ណោះ។
*   **ភាពស៊ីគ្នា:** ធានាថា Containers របស់អ្នកដំណើរការក្នុងបរិយាកាសដែលមានសុវត្ថិភាពដូចគ្នា។

### ការកំណត់ SecurityContext ទូទៅ

យើងនឹងស្វែងយល់ពីការកំណត់ទូទៅមួយចំនួនដែលត្រូវបានប្រើប្រាស់នៅកម្រិត Pod និង Container ។

#### ១. នៅកម្រិត Pod (pod.spec.securityContext)

ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Containers ទាំងអស់នៅក្នុង Pod និង Volumes មួយចំនួន។

*   **`runAsUser` / `runAsGroup`:** កំណត់ UID / GID ដែល Container របស់ Pod នឹងដំណើរការ។
*   **`fsGroup`:** កំណត់ Group ID សម្រាប់ Persistent Volumes ដែល Mount ទៅក្នុង Pod ។ Files និង Directories នៅក្នុង Volume ទាំងនោះនឹងជាកម្មសិទ្ធិរបស់ Group ID នេះ។

``` yaml
%%writefile pod-security-context.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-secure-pod
spec:
  securityContext: # កំណត់នៅកម្រិត Pod
    runAsUser: 1000       # កំណត់ UID 1000 សម្រាប់ Processes ទាំងអស់នៅក្នុង Container
    runAsGroup: 3000      # កំណត់ GID 3000 សម្រាប់ Processes ទាំងអស់នៅក្នុង Container
    fsGroup: 2000         # កំណត់ GID 2000 សម្រាប់ Volume Filesystems
  containers:
  - name: my-container
    image: alpine:latest
    command: ["sh", "-c", "id && ls -ld /data && sleep 3600"]
    volumeMounts:
    - name: my-volume
      mountPath: /data
  volumes:
  - name: my-volume
    emptyDir: {}
```
``` yaml
!kubectl apply -f pod-security-context.yaml
!kubectl get pod my-secure-pod
!kubectl wait --for=condition=Ready pod/my-secure-pod --timeout=60s
!kubectl logs my-secure-pod
```

**ការពន្យល់:**

*   `id` command នៅក្នុង Log Output បង្ហាញ `uid=1000(nonrootuser) gid=3000(nonrootgroup) groups=3000(nonrootgroup)` (ឈ្មោះ user/group អាចប្រែប្រួលតាម image)។
*   `ls -ld /data` command បង្ហាញថា Directory `/data` (ដែលជា Volume) មាន `gid=2000` ដែលបានកំណត់ដោយ `fsGroup` ។

#### ២. នៅកម្រិត Container (pod.spec.containers[].securityContext)

ការកំណត់ទាំងនេះត្រូវបានអនុវត្តចំពោះ Container ជាក់លាក់មួយ។

*   **`runAsNonRoot`:** ប្រសិនបើកំណត់ជា `true` Container នឹងបដិសេធមិនដំណើរការជា `root` (UID 0) ទេ។
*   **`readOnlyRootFilesystem`:** ប្រសិនបើកំណត់ជា `true` Filesystem របស់ Container នឹងត្រូវបាន Mount ជា Read-Only ដែលជួយបង្កើនសុវត្ថិភាព។
*   **`allowPrivilegeEscalation`:** កំណត់ថាតើដំណើរការនៅក្នុង Container អាចទទួលបាន Privilege លើសពី Parent Process របស់វាដែរឬទេ។
*   **`capabilities`:** អនុញ្ញាតឱ្យអ្នកបន្ថែម (add) ឬលុប (drop) Linux Capabilities សម្រាប់ Container ។
    *   `DROP_ALL` គឺជាការអនុវត្តដ៏ល្អបំផុតដើម្បីលុប Capabilities ទាំងអស់ដែលមិនចាំបាច់។
    *   `NET_BIND_SERVICE` អនុញ្ញាតឱ្យ Processes Bind Ports តូចជាង 1024 ។

``` yaml
%%writefile container-security-context.yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-secure-container-pod
spec:
  containers:
  - name: my-app-container
    image: nginx:latest
    securityContext: # កំណត់នៅកម្រិត Container
      runAsNonRoot: true         # បដិសេធមិនដំណើរការជា root
      runAsUser: 1001            # កំណត់ UID 1001
      readOnlyRootFilesystem: true # Root Filesystem របស់ Container គឺ Read-Only
      allowPrivilegeEscalation: false # មិនអនុញ្ញាតឱ្យបង្កើន Privilege
      capabilities:
        drop:
          - ALL                 # លុប Capabilities ទាំងអស់
        add:
          - NET_BIND_SERVICE  # បន្ថែម Capability សម្រាប់ Bind Port < 1024 (បើចាំបាច់)
    ports:
    - containerPort: 80 # Nginx ត្រូវការ Bind Port 80
    # ត្រូវ Mount Volume សម្រាប់ Nginx Web Root ប្រសិនបើ readOnlyRootFilesystem គឺ true
    volumeMounts:
    - name: nginx-html
      mountPath: /etc/nginx/conf.d
      readOnly: true
    - name: nginx-html-root
      mountPath: /usr/share/nginx/html
  volumes:
  - name: nginx-html
    emptyDir: {}
  - name: nginx-html-root
    emptyDir: {}
```

``` yaml
!kubectl apply -f container-security-context.yaml
!kubectl get pod my-secure-container-pod
!kubectl wait --for=condition=Ready pod/my-secure-container-pod --timeout=60s
!kubectl describe pod my-secure-container-pod
```

**ការពន្យល់:**

*   នៅក្នុង `describe` output អ្នកនឹងឃើញ `Security Context:` សម្រាប់ Container ដែលបង្ហាញពីការកំណត់ទាំងនេះ។
*   Pod នេះនឹងដំណើរការ Nginx ជា User ID `1001` ហើយ Root Filesystem របស់វាគឺ Read-Only ។

### សរុបមក

**SecurityContext** គឺជាឧបករណ៍ដ៏មានអានុភាពនៅក្នុង Kubernetes សម្រាប់អនុវត្តគោលការណ៍សុវត្ថិភាពនៅកម្រិត Pod និង Container ។ ការកំណត់ `runAsUser`, `runAsGroup`, `fsGroup`, `runAsNonRoot`, `readOnlyRootFilesystem`, និង `capabilities` ជួយកាត់បន្ថយ Surface Area នៃការវាយប្រហារ និងធានាថាកម្មវិធីរបស់អ្នកដំណើរការជាមួយនឹងសិទ្ធិចាំបាច់តែប៉ុណ្ណោះ។ ការអនុវត្ត SecurityContext គឺជាផ្នែកសំខាន់មួយនៃការ Deploy កម្មវិធីដែលមានសុវត្ថិភាពនៅក្នុង Kubernetes Cluster ។

``` yaml
# Clean up
!kubectl delete -f pod-security-context.yaml
!kubectl delete -f container-security-context.yaml
!rm pod-security-context.yaml container-security-context.yaml
```

## ៧.៥ PodDisruptionBudgets (PDBs) (ធានាថា Pods គ្រប់គ្រាន់នៅតែបន្តដំណើរការ)

### អ្វីទៅជា PodDisruptionBudget (PDB)?

**PodDisruptionBudget (PDB)** គឺជា API Object នៅក្នុង Kubernetes ដែលអនុញ្ញាតឱ្យអ្នកកំណត់ចំនួន Pods អប្បបរមាដែលត្រូវតែមាន (minAvailable) ឬចំនួន Pods អតិបរមាដែលអាច Unavailable បាន (maxUnavailable) សម្រាប់កម្មវិធី Stateful ឬ Stateless ក្នុងអំឡុងពេល **Voluntary Disruptions**។ PDBs ជួយធានានូវ Availability របស់កម្មវិធីរបស់អ្នកក្នុងកំឡុងពេល Maintenance ឬ Actions ដែលធ្វើឱ្យ Pods ត្រូវបានលុបដោយចេតនា។

#### អ្វីទៅជា Voluntary Disruptions?

Voluntary Disruptions គឺជាព្រឹត្តិការណ៍ដែល Pods ត្រូវបានលុបដោយចេតនាដោយ Administrator ឬដោយ Cluster Operations ។ ឧទាហរណ៍:

*   **Node Drain:** Administrator ដក Node ចេញពី Cluster សម្រាប់ការថែទាំ ឬ Upgrade ។
*   **Cluster Upgrade:** ការ Upgrade Kubernetes Version ដែលទាមទារឱ្យ Nodes ត្រូវបាន Restart ។
*   **Node Autorepair:** Node ដែលមានបញ្ហាត្រូវបានជួសជុលដោយស្វ័យប្រវត្តិ។

PDBs មិនការពារ Pods ពី Involuntary Disruptions នោះទេ ដូចជា Hardware Failure, Kernel Panic, ឬ Out-Of-Memory (OOM) Kill ។

### ហេតុអ្វីត្រូវប្រើ PDBs?

*   **ធានា Availability:** ធានាថាកម្មវិធីរបស់អ្នកនៅតែបន្តដំណើរការជាមួយនឹងចំនួន Pods គ្រប់គ្រាន់ ទោះបីជាមានការរំខានដោយចេតនាក៏ដោយ។
*   **ការពារពី Downtime:** បង្ការការធ្លាក់ចុះ Performance ឬ Downtime របស់កម្មវិធីដោយសារតែការលុប Pods ច្រើនពេកក្នុងពេលតែមួយ។
*   **សម្រួល Cluster Management:** អនុញ្ញាតឱ្យ Administrator ធ្វើការថែទាំ Cluster (ដូចជា Node Drain) ដោយសុវត្ថិភាព ដោយដឹងថា PDBs នឹងការពារ Workloads សំខាន់ៗ។

### របៀបកំណត់ PDBs

PDB កំណត់លក្ខណៈសម្បត្តិពីរ៖

1.  **`minAvailable`:** កំណត់ចំនួនអប្បបរមានៃ Pods ដែលត្រូវតែមានជា `available` ។ អាចជាចំនួនគត់ (ឧទាហរណ៍ `2`) ឬភាគរយ (ឧទាហរណ៍ `50%`) នៃចំនួន Pods សរុប។
2.  **`maxUnavailable`:** កំណត់ចំនួនអតិបរមានៃ Pods ដែលអាច `unavailable` ។ អាចជាចំនួនគត់ (ឧទាហរណ៍ `1`) ឬភាគរយ (ឧទាហរណ៍ `25%`) នៃចំនួន Pods សរុប។

អ្នកត្រូវតែកំណត់តែមួយក្នុងចំណោម `minAvailable` ឬ `maxUnavailable` ប៉ុណ្ណោះ។

### ឧទាហរណ៍ PodDisruptionBudget (PDB)

យើងនឹងបង្កើត Deployment មួយដែលមាន Pods ចំនួន 3 ហើយបន្ទាប់មកបង្កើត PDB មួយដើម្បីធានាថា Pods យ៉ាងហោចណាស់ 2 តែងតែមាន Available ។

#### ១. Nginx Deployment (nginx-pdb-deployment.yaml)

``` yaml
%%writefile nginx-pdb-deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-app-deployment-pdb
  labels:
    app: nginx-pdb
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx-pdb
  template:
    metadata:
      labels:
        app: nginx-pdb
    spec:
      containers:
      - name: nginx-container
        image: nginx:latest
        ports:
        - containerPort: 80
```

#### ២. PodDisruptionBudget (min-available-pdb.yaml)

``` yaml
%%writefile min-available-pdb.yaml
apiVersion: policy/v1
kind: PodDisruptionBudget
metadata:
  name: nginx-app-pdb
spec:
  minAvailable: 2 # ធានាថា Pods យ៉ាងហោចណាស់ 2 តែងតែមាន Available
  selector:
    matchLabels:
      app: nginx-pdb # PDB នេះនឹងការពារ Pods ដែលមាន Label app: nginx-pdb
```

**ការពន្យល់ពី PDB YAML Fields:**

*   `apiVersion`: សម្រាប់ PDB គឺ `policy/v1` ។
*   `kind`: `PodDisruptionBudget` ។
*   `metadata.name`: ឈ្មោះរបស់ PDB ។
*   `spec.minAvailable: 2`: កំណត់ថា Pods យ៉ាងហោចណាស់ 2 ត្រូវតែមាន Available ជានិច្ច។ ប្រសិនបើមាន Pod តែ 3 វាមានន័យថា Pod យ៉ាងច្រើនបំផុត 1 អាច Unavailable បាន។
*   `spec.selector.matchLabels.app: nginx-pdb`: PDB នេះនឹងអនុវត្តចំពោះ Pods ណាដែលមាន Label `app: nginx-pdb` ។

### Deploy និងផ្ទៀងផ្ទាត់

``` yaml
# Deploy Deployment
!kubectl apply -f nginx-pdb-deployment.yaml

# រង់ចាំ Pods ដំណើរការ
!kubectl wait --for=condition=Ready pod -l app=nginx-pdb --timeout=120s

# ពិនិត្យមើល Pods
!kubectl get pods -l app=nginx-pdb
```

``` yaml
# Deploy PDB
!kubectl apply -f min-available-pdb.yaml
```

#### ពិនិត្យមើល PDB

``` yaml
!kubectl get pdb
!kubectl describe pdb nginx-app-pdb
```

នៅក្នុង Output របស់ `kubectl describe pdb` អ្នកនឹងឃើញព័ត៌មានដូចជា `Min available` (`2`), `Allowed disruptions` (`1`), និង `Current` (`3`) ដែលបង្ហាញថា PDB កំពុងការពារ Deployment របស់អ្នក។ `Allowed disruptions` បង្ហាញពីចំនួន Pods ដែលអាចត្រូវបានលុបបន្ថែមទៀតដោយសុវត្ថិភាព។

### ការសាកល្បង PDB (ឧទាហរណ៍អំពី Node Drain)

ប្រសិនបើ Administrator ព្យាយាម `drain` Node មួយ (ដែលលុប Pods ទាំងអស់នៅលើ Node នោះ) Kubernetes នឹងពិនិត្យមើល PDBs ។ ប្រសិនបើការ `drain` នោះបណ្តាលឱ្យចំនួន Pods ដែលមាន Available ធ្លាក់ចុះក្រោម `minAvailable` របស់ PDB នោះ Kubernetes នឹងបដិសេធមិនព្រមលុប Pods ទៀតទេ (ឬរង់ចាំរហូតដល់លក្ខខណ្ឌត្រូវបានបំពេញ) ។

សម្រាប់គោលបំណងបង្ហាញ យើងនឹងព្យាយាម Drain Node `minikube` ដែលមាន Pods របស់យើង។ ដោយសារយើងមាន PDB ដែលអនុញ្ញាតឱ្យមាន Disruption ត្រឹមតែ 1 Pod ប៉ុណ្ណោះ វានឹងព្យាយាម Drain Pod មួយ ហើយបន្ទាប់មកនឹងជាប់គាំង ដោយសារវាត្រូវការលុប Pod មួយទៀត ប៉ុន្តែ PDB ការពារវា។

**ចំណាំ:** Command `kubectl drain` អាចចំណាយពេលខ្លះ ឬអាចជាប់គាំង (hang) ប្រសិនបើ PDB ការពារ Pods មិនឱ្យត្រូវបានលុប។ អ្នកអាចប្រើ `Ctrl+C` ដើម្បីបញ្ឈប់វា។

``` yaml
# ព្យាយាម Drain Node (Pod មួយនឹងត្រូវ evicted បន្ទាប់មកវានឹងជាប់គាំង)
# ចុច Ctrl+C ដើម្បីបញ្ឈប់ command នេះបន្ទាប់ពីវាចាប់ផ្តើមដំណើរការ
!kubectl drain minikube --ignore-daemonsets --delete-emptydir-data --force
```
