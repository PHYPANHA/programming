# ជំពូកទី ៣៖ គំនិតសំខាន់ៗជាមូលដ្ឋាន (Core Concepts)

## ៣.១ Pods (ការពន្យល់ និងរបៀបសរសេរ YAML សម្រាប់ Pod)

### អ្វីទៅជា Pod?

នៅក្នុង Kubernetes, **Pod** គឺជា Unit តូចបំផុតដែលអាច Deploy បាន។ Pod តំណាងឱ្យ Instance តែមួយនៃកម្មវិធីដែលកំពុងដំណើរការ។ Pod អាចមាន Container មួយ ឬច្រើនដែលចែករំលែក Resources ដូចជា Network Namespace, Storage Volumes, និង Linux Namespaces (PID, Mount, IPC, UTS)។

**ចំណុចសំខាន់ៗអំពី Pods:**

*   **Atomic Unit:** Pod ត្រូវបានចាត់ទុកជា Atomic Unit សម្រាប់ Deployment, Scaling, និង Scheduling។ អ្នកមិនអាច Deploy Container តែមួយដោយផ្ទាល់ទៅកាន់ Kubernetes Cluster បានទេ។ Container តែងតែត្រូវបានដាក់នៅក្នុង Pod មួយ។
*   **Single IP Address:** Pod នីមួយៗត្រូវបានផ្តល់ IP Address តែមួយគត់នៅក្នុង Cluster ។ Containers នៅក្នុង Pod តែមួយអាចទំនាក់ទំនងគ្នាដោយប្រើ `localhost`។
*   **Shared Resources:** Containers នៅក្នុង Pod មួយចែករំលែក Resources ដូចជា Network (IP address, network ports) និង Storage (shared Volumes) ។
*   **Ephemeral:** Pods គឺ Ephemeral មានន័យថាពួកវាអាចត្រូវបានបង្កើត, លុប, ឬចាប់ផ្តើមឡើងវិញ។ នៅពេល Pod ត្រូវបានលុប ទិន្នន័យណាមួយដែលមិនត្រូវបានរក្សាទុកនៅក្នុង Persistent Volume នឹងបាត់បង់។
*   **Why Multiple Containers in a Pod? (Sidecar Pattern):** ទោះបីជា Pod ភាគច្រើនមាន Container តែមួយក៏ដោយ ជួនកាលយើងដាក់ Containers ច្រើននៅក្នុង Pod មួយដើម្បីឱ្យពួកវាធ្វើការជាមួយគ្នាយ៉ាងជិតស្និទ្ធ (ឧទាហរណ៍ Sidecar pattern)។ ឧទាហរណ៍៖ Container សំខាន់ដំណើរការកម្មវិធី ហើយ Container មួយទៀត (Sidecar) ដំណើរការ Logging Agent ឬ Data Synchronizer សម្រាប់កម្មវិធីនោះ។

### របៀបសរសេរ YAML សម្រាប់ Pod

Kubernetes Resources ទាំងអស់ត្រូវបានកំណត់ដោយប្រើ YAML (ឬ JSON) ។ ខាងក្រោមនេះគឺជាឧទាហរណ៍នៃ Pod Definition YAML ដែលដំណើរការ Container មួយ។

**ឧទាហរណ៍ Pod YAML (nginx-pod.yaml):**

```yaml
apiVersion: v1 # កំណត់ Kubernetes API version ដែលកំពុងប្រើ
kind: Pod # កំណត់ប្រភេទ Resource នេះគឺ Pod
metadata: # Metadata អំពី Pod
  name: nginx-pod # ឈ្មោះរបស់ Pod
  labels: # Labels សម្រាប់កំណត់អត្តសញ្ញាណ Pod នេះ
    app: nginx
    tier: frontend
spec: # Specification (លក្ខណៈបច្ចេកទេស) របស់ Pod
  containers: # បញ្ជីនៃ Containers ដែលនឹងដំណើរការនៅក្នុង Pod នេះ
    - name: nginx-container # ឈ្មោះរបស់ Container
      image: nginx:latest # Image ដែលត្រូវប្រើសម្រាប់ Container នេះ
      ports: # Port ដែល Container នេះបើក
        - containerPort: 80
      resources: # ការកំណត់ Resource Limits និង Requests សម្រាប់ Container
        requests: # Resource ដែល Container ត្រូវការជាអប្បបរមា
          memory: "64Mi"
          cpu: "250m" # 250 milli-CPU (1/4 នៃ CPU Core)
        limits: # Resource អតិបរមាដែល Container អាចប្រើបាន
          memory: "128Mi"
          cpu: "500m"
```

**ការពន្យល់ពី YAML Fields:**

*   `apiVersion`: កំណត់ Kubernetes API version ដែលអ្នកកំពុងប្រើដើម្បីបង្កើត Resource នេះ។ សម្រាប់ Pods គឺ `v1`។
*   `kind`: បញ្ជាក់ប្រភេទនៃ Kubernetes Resource ដែលអ្នកកំពុងបង្កើត។ ក្នុងករណីនេះគឺ `Pod`។
*   `metadata`: រួមបញ្ចូលទិន្នន័យដែលជួយកំណត់អត្តសញ្ញាណ Resource តែមួយគត់ ដូចជា `name` និង `labels`។
    *   `name`: ឈ្មោះដែលកំណត់ Pod របស់អ្នក។ ឈ្មោះនេះត្រូវតែប្លែកក្នុង Namespace របស់វា។
    *   `labels`: ជា Key-Value pairs ដែលត្រូវបានប្រើដើម្បីភ្ជាប់ metadata ទៅនឹង Resources របស់ Kubernetes ។ Labels មានសារៈសំខាន់ខ្លាំងណាស់សម្រាប់ការរៀបចំ និងការជ្រើសរើស (selecting) Resources (ឧទាហរណ៍ Services ប្រើ Labels ដើម្បីជ្រើសរើស Pods ដែលត្រូវ Load Balance)។
*   `spec`: គឺជា Object ដែលមានលក្ខណៈបច្ចេកទេស (specifications) របស់ Resource។ សម្រាប់ Pod វាកំណត់ Container(s) ដែលត្រូវដំណើរការ របៀបកំណត់ Network, Storage, និង Resource Requirements ។
    *   `containers`: ជា Array នៃ Objects ដែលនីមួយៗកំណត់ Container មួយ។
        *   `name`: ឈ្មោះរបស់ Container នៅក្នុង Pod នេះ។
        *   `image`: Docker Image ដែល Container នេះនឹងប្រើ។ (ឧទាហរណ៍ `nginx:latest` នឹងទាញយក Image របស់ Nginx Version ចុងក្រោយបំផុត)។
        *   `ports`: Array នៃ Port ដែល Container បើក។ `containerPort` គឺជា Port ខាងក្នុងរបស់ Container ។
        *   `resources`: កំណត់ `requests` (ធានា Resource អប្បបរមា) និង `limits` (ធានា Resource អតិបរមា) សម្រាប់ CPU និង Memory។

### ការ Deploy Pod ដោយប្រើ kubectl

1.  **រក្សាទុក YAML ខាងលើ:** រក្សាទុក Code YAML ខាងលើទៅក្នុង File មួយឈ្មោះ `nginx-pod.yaml` ។

2.  **Deploy Pod ទៅកាន់ Kubernetes Cluster:**
    ```bash
    kubectl apply -f nginx-pod.yaml
    ```
    *   **ការពន្យល់:** Command នេះប្រាប់ Kubernetes ឱ្យបង្កើត Resource ដែលបានកំណត់នៅក្នុង `nginx-pod.yaml` ។

3.  **ផ្ទៀងផ្ទាត់ថា Pod កំពុងដំណើរការ:**
    ```bash
    kubectl get pods
    ```
    អ្នកគួរតែឃើញ `nginx-pod` ជាមួយនឹង Status `Running` ។

    ```bash
    # ឧទាហរណ៍ Output
    NAME        READY   STATUS    RESTARTS   AGE
    nginx-pod   1/1     Running   0          2m
    ```

4.  **មើលព័ត៌មានលម្អិតរបស់ Pod:**
    ```bash
    kubectl describe pod nginx-pod
    ```
    *   **ការពន្យល់:** នេះនឹងបង្ហាញព័ត៌មានលម្អិតទាំងអស់អំពី Pod របស់អ្នក រួមទាំង Events ដែលមានប្រយោជន៍សម្រាប់ការ Debugging ។

5.  **មើល Logs របស់ Container:**
    ```bash
    kubectl logs nginx-pod
    ```
    *   **ការពន្យល់:** នេះនឹងបង្ហាញ Logs ពី Nginx Container ។

6.  **លុប Pod:**
    ```bash
    kubectl delete -f nginx-pod.yaml
    # ឬ
    kubectl delete pod nginx-pod
    ```
    *   **ការពន្យល់:** Command នេះនឹងលុប `nginx-pod` ចេញពី Cluster របស់អ្នក។

### Pods និង Lifecycle

Pods គឺជា Ephemeral ហើយ Kubernetes មិនធានាថា Pod នឹងនៅស្ថិតស្ថេរជាអចិន្ត្រៃយ៍នោះទេ។ ប្រសិនបើ Node ដែល Pod កំពុងដំណើរការបរាជ័យ Pod នឹងត្រូវលុបចោល។ នៅក្នុងជំពូកបន្ទាប់ យើងនឹងរៀនពីរបៀបប្រើ `ReplicaSets` និង `Deployments` ដើម្បីគ្រប់គ្រង Lifecycle របស់ Pods ដោយស្វ័យប្រវត្តិ និងធានានូវ High Availability ។

## ៣.២ ReplicaSets (ការគ្រប់គ្រងចំនួន Pods)

នៅក្នុងផ្នែកមុន យើងបានរៀនអំពី Pods ដែលជា Unit តូចបំផុតដែលអាច Deploy បាន។ ទោះជាយ៉ាងណាក៏ដោយ Pods មានលក្ខណៈ Ephemeral (បណ្ដោះអាសន្ន) ដែលមានន័យថាប្រសិនបើ Pod ណាមួយបរាជ័យ ឬ Node ដែល Pod កំពុងដំណើរការ Offline, Pod នោះនឹងបាត់បង់ទៅ។ នេះជាបញ្ហាសម្រាប់កម្មវិធីដែលត្រូវការ High Availability និង Consistency។

ដើម្បីដោះស្រាយបញ្ហានេះ Kubernetes បានណែនាំ **ReplicaSets**។

### អ្វីទៅជា ReplicaSet?

**ReplicaSet** គឺជា Kubernetes Controller ដែលធានាថាចំនួន Pods ដែលបានកំណត់ (desired number of Pods) សម្រាប់កម្មវិធីមួយនៅតែបន្តដំណើរការជានិច្ច។

**មុខងារសំខាន់ៗរបស់ ReplicaSet:**

*   **ធានាចំនួន Pods:** ប្រសិនបើ Pod ណាមួយបរាជ័យ ReplicaSet នឹងបង្កើត Pod ថ្មីមួយដើម្បីជំនួសភ្លាមៗ។ ប្រសិនបើ Pod ច្រើនជាងចំនួនដែលបានកំណត់ ReplicaSet នឹងលុប Pods លើសចោល។
*   **Scaling:** អ្នកអាចផ្លាស់ប្តូរចំនួន Replicas របស់ ReplicaSet ដើម្បី Scale Up (បង្កើនចំនួន Pods) ឬ Scale Down (បន្ថយចំនួន Pods) កម្មវិធីរបស់អ្នក។
*   **Selection:** ReplicaSet ប្រើ Labels ដើម្បីកំណត់អត្តសញ្ញាណ Pods ដែលវាគួរតែគ្រប់គ្រង។

### របៀបសរសេរ YAML សម្រាប់ ReplicaSet

ខាងក្រោមនេះគឺជាឧទាហរណ៍នៃ ReplicaSet Definition YAML ដែលនឹងធានាថាមាន Pod Nginx ចំនួន 3 កំពុងដំណើរការជានិច្ច។

**ឧទាហរណ៍ ReplicaSet YAML (nginx-replicaset.yaml):**

```yaml
apiVersion: apps/v1 # កំណត់ Kubernetes API version (សម្រាប់ ReplicaSet គឺ apps/v1)
kind: ReplicaSet # កំណត់ប្រភេទ Resource នេះគឺ ReplicaSet
metadata:
  name: nginx-replicaset # ឈ្មោះរបស់ ReplicaSet
spec:
  replicas: 3 # ចំនួន Pods ដែល ReplicaSet គួរតែរក្សាទុក
  selector: # ReplicaSet ប្រើ Selector ដើម្បីកំណត់ Pods ដែលវាគ្រប់គ្រង
    matchLabels:
      app: nginx
  template: # Template សម្រាប់ Pods ដែល ReplicaSet នឹងបង្កើត
    metadata:
      labels:
        app: nginx # Labels ទាំងនេះត្រូវតែត្រូវគ្នាជាមួយ selector.matchLabels
    spec:
      containers:
      - name: nginx-container
        image: nginx:latest
        ports:
        - containerPort: 80
```

**ការពន្យល់ពី YAML Fields:**

*   `apiVersion`: សម្រាប់ ReplicaSet គឺ `apps/v1` ។
*   `kind`: `ReplicaSet` ។
*   `metadata.name`: ឈ្មោះរបស់ ReplicaSet ។
*   `spec.replicas`: ចំនួន Pods ដែលយើងចង់ឱ្យដំណើរការជានិច្ច។ ក្នុងឧទាហរណ៍នេះគឺ `3` ។
*   `spec.selector`: គឺជា Field សំខាន់ដែលប្រាប់ ReplicaSet ពី Pods ណាដែលវាគួរតែគ្រប់គ្រង។ Selector ប្រើ `matchLabels` ដើម្បីផ្គូផ្គង Pods ជាមួយ Labels ជាក់លាក់។ នៅក្នុងឧទាហរណ៍នេះ ReplicaSet នឹងគ្រប់គ្រង Pods ណាដែលមាន Label `app: nginx` ។
*   `spec.template`: គឺជា Pod Template ដែល ReplicaSet នឹងប្រើដើម្បីបង្កើត Pods ថ្មី។
    *   `metadata.labels`: Labels នៅក្នុង Pod Template នេះ *ត្រូវតែ* ត្រូវគ្នាជាមួយ `spec.selector.matchLabels` ។ បើមិនដូច្នេះទេ ReplicaSet នឹងមិនអាចគ្រប់គ្រង Pods ដែលវាបង្កើតបានត្រឹមត្រូវទេ។
    *   `spec`: គឺជា Pod Specification ដែលយើងបានរៀននៅក្នុងផ្នែក ៣.១ ។

### ការ Deploy ReplicaSet ដោយប្រើ kubectl

1.  **រក្សាទុក YAML ខាងលើ:** រក្សាទុក Code YAML ខាងលើទៅក្នុង File មួយឈ្មោះ `nginx-replicaset.yaml` ។

2.  **Deploy ReplicaSet ទៅកាន់ Kubernetes Cluster:**
    ```bash
    kubectl apply -f nginx-replicaset.yaml
    ```

3.  **ផ្ទៀងផ្ទាត់ថា ReplicaSet កំពុងដំណើរការ:**
    ```bash
    kubectl get replicasets
    ```
    អ្នកគួរតែឃើញ `nginx-replicaset` ជាមួយនឹង `DESIRED`, `CURRENT`, និង `READY` Pods ចំនួន `3` ។

    ```bash
    # ឧទាហរណ៍ Output
    NAME                 DESIRED   CURRENT   READY   AGE
    nginx-replicaset     3         3         3       1m
    ```

4.  **ផ្ទៀងផ្ទាត់ Pods ដែលត្រូវបានបង្កើតដោយ ReplicaSet:**
    ```bash
    kubectl get pods -l app=nginx
    ```
    *   **ការពន្យល់:** យើងប្រើ `-l app=nginx` ដើម្បី Filter Pods ណាដែលមាន Label `app: nginx` ។ អ្នកគួរតែឃើញ Pods ចំនួន 3 ដែលមានឈ្មោះស្រដៀងនឹង `nginx-replicaset-xxxxx` ។

5.  **សាកល្បងលុប Pod មួយ:**
    ```bash
    kubectl delete pod <ឈ្មោះ Pod ណាមួយដែល ReplicaSet បានបង្កើត>
    ```
    *   **ការពន្យល់:** ភ្លាមៗនោះ ReplicaSet នឹងរកឃើញថាចំនួន Pods មិនគ្រប់គ្រាន់ ហើយនឹងបង្កើត Pod ថ្មីមួយដើម្បីជំនួស។ អ្នកអាចពិនិត្យមើល `kubectl get pods` ម្តងទៀតដើម្បីមើល Pod ថ្មី។

### ការ Scale ReplicaSet

អ្នកអាច Scale ReplicaSet តាមពីរវិធី:

1.  **ដោយកែសម្រួល File YAML រួច `apply` ឡើងវិញ:**
    *   កែសម្រួល `nginx-replicaset.yaml` ហើយផ្លាស់ប្តូរ `replicas: 3` ទៅ `replicas: 5` (ឬលេខផ្សេង)។
    *   បន្ទាប់មកដំណើរការ `kubectl apply -f nginx-replicaset.yaml` ម្តងទៀត។

2.  **ដោយប្រើ Command `kubectl scale`:**
    ```bash
    kubectl scale replicaset nginx-replicaset --replicas=5
    ```
    *   **ការពន្យល់:** Command នេះនឹងផ្លាស់ប្តូរចំនួន Replicas របស់ ReplicaSet ទៅ 5 ។ ReplicaSet នឹងបង្កើត Pods ថ្មីចំនួន 2 (ពី 3 ទៅ 5) ។

### ដែនកំណត់របស់ ReplicaSets

ខណៈពេលដែល ReplicaSet ដោះស្រាយបញ្ហា High Availability របស់ Pods បានយ៉ាងល្អឥតខ្ចោះ វាមិនមានលទ្ធភាពក្នុងការធ្វើ Update កម្មវិធីដោយរលូននោះទេ។ ប្រសិនបើអ្នកចង់ Update Image របស់ Nginx ពី `nginx:latest` ទៅ `nginx:1.21` អ្នកត្រូវតែលុប ReplicaSet ចាស់ចោល ហើយបង្កើតថ្មីមួយ ដែលអាចបណ្តាលឱ្យមាន Downtime ។

សម្រាប់ Use Cases ដែលទាមទារការ Update ដោយគ្មាន Downtime (Zero-downtime deployments) និង Rollbacks, Kubernetes ផ្តល់ជូននូវ Resource មួយទៀតគឺ **Deployments** ដែលយើងនឹងរៀននៅក្នុងផ្នែកបន្ទាប់។ ជាធម្មតា អ្នកមិនធ្វើការជាមួយ ReplicaSet ដោយផ្ទាល់នោះទេ គឺ Deployment Controller ជាអ្នកបង្កើត និងគ្រប់គ្រង ReplicaSet សម្រាប់អ្នក។

## ៣.៣ Deployments (ការធ្វើបច្ចុប្បន្នភាព និង Rollback)

នៅក្នុងផ្នែកមុន យើងបានរៀនអំពី ReplicaSets ដែលអាចធានាថាកម្មវិធីរបស់យើងមានចំនួន Pods គ្រប់គ្រាន់ដើម្បីដំណើរការជានិច្ច។ ទោះជាយ៉ាងណាក៏ដោយ ReplicaSets មានដែនកំណត់មួយគឺ វាមិនអាចធ្វើការ Update កម្មវិធីរបស់យើងទៅ Version ថ្មីដោយរលូន (Zero-downtime) និងមិនអាច Rollback ទៅ Version ចាស់បានទេ។

ដើម្បីដោះស្រាយបញ្ហានេះ Kubernetes បានបង្កើត **Deployments** ។

### អ្វីទៅជា Deployment?

**Deployment** គឺជា Kubernetes Controller មួយកម្រិតខ្ពស់ជាង (Higher-level abstraction) ដែលផ្តល់នូវ Declarative Updates សម្រាប់ Pods និង ReplicaSets ។ Deployment អនុញ្ញាតឱ្យអ្នកកំណត់ `desired state` សម្រាប់កម្មវិធីរបស់អ្នក ហើយ Deployment Controller នឹងផ្លាស់ប្តូរ `actual state` ទៅជា `desired state` ក្នុងអត្រាដែលបានគ្រប់គ្រង។

**មុខងារសំខាន់ៗរបស់ Deployment:**

*   **ការគ្រប់គ្រង ReplicaSets:** Deployment គឺជាអ្នកបង្កើត (creator) និងអ្នកគ្រប់គ្រង (manager) របស់ ReplicaSets។ រាល់ពេលអ្នកបង្កើត Deployment វាបង្កើត ReplicaSet មួយ។ រាល់ពេលអ្នក Update Deployment វាបង្កើត ReplicaSet ថ្មីមួយ និងគ្រប់គ្រងការផ្លាស់ប្តូរពី ReplicaSet ចាស់ទៅថ្មី។
*   **Rollout Strategy:** ផ្តល់នូវវិធីសាស្រ្ត Rollout ជាច្រើន (ឧទាហរណ៍ `RollingUpdate` ដែលជា Default) ដើម្បី Update កម្មវិធីដោយគ្មាន Downtime។
*   **Rollback:** អនុញ្ញាតឱ្យអ្នក Rollback កម្មវិធីទៅ Version មុនបានយ៉ាងងាយស្រួល ប្រសិនបើមានបញ្ហា។
*   **Pause and Resume:** អ្នកអាច Pause Deployment ដើម្បីធ្វើការកែប្រែច្រើន រួច Resume វិញដើម្បីអនុវត្តការកែប្រែទាំងអស់តែម្តង។

### របៀបសរសេរ YAML សម្រាប់ Deployment

ខាងក្រោមនេះគឺជាឧទាហរណ៍នៃ Deployment Definition YAML ដែលនឹងបង្កើត Pods Nginx ចំនួន 3 ។

**ឧទាហរណ៍ Deployment YAML (nginx-deployment.yaml):**

```yaml
apiVersion: apps/v1 # កំណត់ Kubernetes API version (សម្រាប់ Deployment គឺ apps/v1)
kind: Deployment # កំណត់ប្រភេទ Resource នេះគឺ Deployment
metadata:
  name: nginx-deployment # ឈ្មោះរបស់ Deployment
  labels:
    app: nginx
spec:
  replicas: 3 # ចំនួន Pods ដែល Deployment គួរតែរក្សាទុក
  selector: # Deployment ប្រើ Selector ដើម្បីកំណត់ Pods ដែលវាគ្រប់គ្រង
    matchLabels:
      app: nginx
  template: # Template សម្រាប់ Pods ដែល Deployment នឹងបង្កើត
    metadata:
      labels:
        app: nginx # Labels ទាំងនេះត្រូវតែត្រូវគ្នាជាមួយ selector.matchLabels
    spec:
      containers:
      - name: nginx-container
        image: nginx:1.14.2 # Image ដែលត្រូវប្រើសម្រាប់ Container នេះ
        ports:
        - containerPort: 80
  strategy: # កំណត់ Deployment Strategy (Default គឺ RollingUpdate)
    type: RollingUpdate
    rollingUpdate:
      maxUnavailable: 25% # អតិបរមា 25% នៃ Pods អាច Offline បានក្នុងពេល Update
      maxSurge: 25% # អតិបរមា 25% នៃ Pods អាចត្រូវបានបង្កើតលើសពី Replicas Count
```

**ការពន្យល់ពី YAML Fields (ចំណុចបន្ថែមលើ ReplicaSet):**

*   `kind`: `Deployment` ។
*   `spec.strategy`: កំណត់យុទ្ធសាស្ត្រសម្រាប់ការ Update ។
    *   `type: RollingUpdate`: ជា Default ហើយជាយុទ្ធសាស្ត្រដែលត្រូវបានប្រើច្រើនបំផុត។ វាបង្កើត Pod ថ្មីម្តងមួយៗ ខណៈពេលដែលលុប Pod ចាស់ចោលបន្តិចម្តងៗ។
    *   `maxUnavailable`: ចំនួន ឬភាគរយអតិបរមានៃ Pods ដែលអាច Unavailable បានក្នុងពេល Update។
    *   `maxSurge`: ចំនួន ឬភាគរយអតិបរមានៃ Pods ដែលអាចត្រូវបានបង្កើតលើសពីចំនួន `replicas` ដែលបានកំណត់។

### ការ Deploy Deployment ដោយប្រើ kubectl

1.  **រក្សាទុក YAML ខាងលើ:** រក្សាទុក Code YAML ខាងលើទៅក្នុង File មួយឈ្មោះ `nginx-deployment.yaml` ។

2.  **Deploy Deployment ទៅកាន់ Kubernetes Cluster:**
    ```bash
    kubectl apply -f nginx-deployment.yaml
    ```

3.  **ផ្ទៀងផ្ទាត់ថា Deployment កំពុងដំណើរការ:**
    ```bash
    kubectl get deployments
    ```
    អ្នកគួរតែឃើញ `nginx-deployment` ជាមួយនឹង `READY` Pods ចំនួន `3` ។

    ```bash
    # ឧទាហរណ៍ Output
    NAME               READY   UP-TO-DATE   AVAILABLE   AGE
    nginx-deployment   3/3     3            3           1m
    ```

4.  **ពិនិត្យមើល ReplicaSet ដែល Deployment បានបង្កើត:**
    ```bash
    kubectl get replicasets
    ```
    អ្នកនឹងឃើញ ReplicaSet មួយដែលមានឈ្មោះស្រដៀងនឹង `nginx-deployment-xxxxx` ។

5.  **ពិនិត្យមើល Pods ដែលត្រូវបានបង្កើតដោយ Deployment (តាមរយៈ ReplicaSet):**
    ```bash
    kubectl get pods -l app=nginx
    ```

### ការ Update Deployment (Rolling Update)

ឥឡូវនេះយើងនឹង Update Image របស់ Nginx ពី `nginx:1.14.2` ទៅ `nginx:latest` ។

1.  **កែសម្រួល File YAML:** បើក `nginx-deployment.yaml` ហើយផ្លាស់ប្តូរ `image: nginx:1.14.2` ទៅ `image: nginx:latest` ។

2.  **អនុវត្តការផ្លាស់ប្តូរ:**
    ```bash
    kubectl apply -f nginx-deployment.yaml
    ```

3.  **តាមដានដំណើរការ Update:**
    ```bash
    kubectl get deployments -w # -w សម្រាប់ watch (មើលការផ្លាស់ប្តូរក្នុងពេលជាក់ស្តែង)
    ```
    អ្នកនឹងឃើញ Deployment ធ្វើការបង្កើត Pods ថ្មីបន្តិចម្តងៗជាមួយ Image ថ្មី ហើយលុប Pods ចាស់ចោល។

4.  **ពិនិត្យមើល ReplicaSets ម្តងទៀត:**
    ```bash
    kubectl get replicasets
    ```
    អ្នកនឹងឃើញ ReplicaSet ថ្មីមួយ (ជាមួយនឹង Pods `3`) ហើយ ReplicaSet ចាស់នឹងមាន Pods `0` ។

### ការ Rollback Deployment

ប្រសិនបើការ Update របស់អ្នកមានបញ្ហា អ្នកអាច Rollback ទៅ Version មុនបានយ៉ាងងាយស្រួល។

1.  **ពិនិត្យមើល History របស់ Deployment:**
    ```bash
    kubectl rollout history deployment nginx-deployment
    ```
    អ្នកនឹងឃើញ Revision Number សម្រាប់ Deployment នីមួយៗ។

2.  **Rollback ទៅ Revision មុន:**
    ```bash
    kubectl rollout undo deployment nginx-deployment
    ```
    *   **ការពន្យល់:** Command នេះនឹង Rollback Deployment ទៅ Revision មុន។ Deployment នឹងធ្វើការផ្លាស់ប្តូរ Pods ត្រឡប់ទៅ Image ចាស់វិញ។

3.  **Rollback ទៅ Revision ជាក់លាក់:**
    ```bash
    kubectl rollout undo deployment nginx-deployment --to-revision=1
    ```
    *   **ការពន្យល់:** Command នេះនឹង Rollback Deployment ទៅ Revision Number ដែលអ្នកបានបញ្ជាក់ (ឧទាហរណ៍ Revision 1) ។

### ការ Scale Deployment

ដូច ReplicaSet ដែរ អ្នកអាច Scale Deployment តាមពីរវិធី:

1.  **កែសម្រួល File YAML រួច `apply` ឡើងវិញ:**
    *   កែសម្រួល `nginx-deployment.yaml` ហើយផ្លាស់ប្តូរ `replicas: 3` ទៅ `replicas: 5` ។
    *   បន្ទាប់មកដំណើរការ `kubectl apply -f nginx-deployment.yaml` ម្តងទៀត។

2.  **ដោយប្រើ Command `kubectl scale`:**
    ```bash
    kubectl scale deployment nginx-deployment --replicas=5
    ```

### ការលុប Deployment

*   **លុប Deployment:**
    ```bash
    kubectl delete -f nginx-deployment.yaml
    # ឬ
    kubectl delete deployment nginx-deployment
    ```
    *   **ការពន្យល់:** ការលុប Deployment នឹងលុប ReplicaSets និង Pods ទាំងអស់ដែលពាក់ព័ន្ធដោយស្វ័យប្រវត្តិ។

### សរុបមក

Deployments គឺជា Resource ដ៏សំខាន់សម្រាប់គ្រប់គ្រង Lifecycle របស់កម្មវិធីនៅក្នុង Kubernetes ។ វាអនុញ្ញាតឱ្យអ្នក Deploy, Update, និង Rollback កម្មវិធីរបស់អ្នកដោយភាពងាយស្រួល និងធានានូវ Zero-downtime សម្រាប់អ្នកប្រើប្រាស់។ សម្រាប់ Use Cases ភាគច្រើន អ្នកនឹងធ្វើការជាមួយ Deployments ជាជាង ReplicaSets ដោយផ្ទាល់។

## ៣.៤ Namespaces (ការបែងចែកបរិស្ថានការងារ)

នៅពេលដែល Kubernetes Cluster របស់អ្នករីកធំ ហើយមានក្រុមការងារជាច្រើនកំពុងប្រើប្រាស់វាសម្រាប់ Deploy កម្មវិធីផ្សេងៗគ្នា វាជារឿងសំខាន់ក្នុងការបែងចែក Resources របស់ Cluster ទៅជាផ្នែកតូចៗដែលឯករាជ្យពីគ្នា។ នេះគឺជាកន្លែងដែល **Namespaces** ដើរតួនាទីយ៉ាងសំខាន់។

### អ្វីទៅជា Namespace?

**Namespace** គឺជាវិធីមួយដើម្បីបែងចែក Resources របស់ Cluster ទៅជា Virtual Clusters នៅក្នុង Physical Cluster តែមួយ។ Resources នៅក្នុង Namespace មួយត្រូវបានបំបែកចេញពី Resources នៅក្នុង Namespaces ផ្សេងទៀត។

**មុខងារសំខាន់ៗរបស់ Namespaces:**

*   **ការបែងចែក Resources (Resource Isolation):** Namespaces ផ្តល់នូវវិសាលភាព (scope) សម្រាប់ Resources ដូចជា Pods, Deployments, Services, ConfigMaps, Secrets ជាដើម។ Resource នីមួយៗនៅក្នុង Kubernetes អាចមាននៅក្នុង Namespace តែមួយគត់។
*   **ការគ្រប់គ្រង Access (Access Control):** Namespaces ត្រូវបានប្រើជាញឹកញាប់ក្នុងការភ្ជាប់ជាមួយ Role-Based Access Control (RBAC) ដើម្បីកំណត់សិទ្ធិអ្នកប្រើប្រាស់ ឬ Service Account ទៅកាន់ Resources ជាក់លាក់នៅក្នុង Namespace ជាក់លាក់មួយ។ ឧទាហរណ៍ អ្នកប្រើប្រាស់ម្នាក់អាចមានសិទ្ធិ Deploy កម្មវិធីនៅក្នុង `dev` Namespace ប៉ុន្តែមិនមានសិទ្ធិនៅក្នុង `prod` Namespace នោះទេ។
*   **ការបែងចែកបរិស្ថាន (Environment Separation):** ជាទូទៅ Namespaces ត្រូវបានប្រើដើម្បីបំបែកបរិស្ថានការងារដូចជា `development` (dev), `staging`, `production` (prod) នៅក្នុង Cluster តែមួយ។
*   **ជម្លោះឈ្មោះ (Name Conflicts):** Namespaces ជួយជៀសវាងជម្លោះឈ្មោះ។ អ្នកអាចមាន Pod មួយឈ្មោះ `my-app` នៅក្នុង `dev` Namespace និង Pod មួយទៀតឈ្មោះ `my-app` នៅក្នុង `prod` Namespace ។

### Namespaces លំនាំដើម (Default Namespaces)

Kubernetes Cluster នីមួយៗមាន Namespaces លំនាំដើមជាច្រើន:

*   **`default`:** សម្រាប់ Resources ដែលមិនបានបញ្ជាក់ Namespace ។
*   **`kube-system`:** សម្រាប់ Objects ដែលបង្កើតដោយ Kubernetes System (ឧទាហរណ៍ `kube-apiserver`, `kube-scheduler`) ។
*   **`kube-public`:** Namespace នេះអាចអានបានដោយអ្នកប្រើប្រាស់ទាំងអស់ (សូម្បីតែអ្នកដែលមិនមានការផ្ទៀងផ្ទាត់)។ វាត្រូវបានប្រើសម្រាប់ Cluster Resources ដែលអាចអានបានដោយសាធារណៈ។
*   **`kube-node-lease`:** Namespace សម្រាប់ Node Lease objects ដែលត្រូវបានប្រើដោយ Nodes ដើម្បីផ្ញើ Heartbeat ទៅកាន់ Control Plane ។

### ការបង្កើត Namespace

អ្នកអាចបង្កើត Namespace ដោយប្រើ `kubectl create namespace` command ឬដោយប្រើ File YAML ។

**១. ដោយប្រើ Command Line:**

```bash
kubectl create namespace development
kubectl create namespace production
```

**២. ដោយប្រើ File YAML:**

**ឧទាហរណ៍ Namespace YAML (dev-namespace.yaml):**

```yaml
apiVersion: v1
kind: Namespace
metadata:
  name: development
```

រក្សាទុកទៅក្នុង `dev-namespace.yaml` រួច Deploy:

```bash
kubectl apply -f dev-namespace.yaml
```

### ការមើល Namespaces

```bash
kubectl get namespaces
```

**ឧទាហរណ៍ Output:**

```bash
NAME              STATUS   AGE
default           Active   2d
development       Active   5s
kube-node-lease   Active   2d
kube-public       Active   2d
kube-system       Active   2d
production        Active   5s
```

### ការ Deploy Resources ទៅកាន់ Namespace ជាក់លាក់

ដើម្បី Deploy Resource ទៅកាន់ Namespace ជាក់លាក់មួយ អ្នកត្រូវបញ្ជាក់ `metadata.namespace` នៅក្នុង File YAML របស់ Resource នោះ។

**ឧទាហរណ៍ Deployment នៅក្នុង `development` Namespace (nginx-dev-deployment.yaml):**

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-dev-deployment
  namespace: development # បញ្ជាក់ Namespace នៅទីនេះ
  labels:
    app: nginx
spec:
  replicas: 2
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx-container
        image: nginx:latest
        ports:
        - containerPort: 80
```

Deploy Deployment នេះ:

```bash
kubectl apply -f nginx-dev-deployment.yaml
```

### ការមើល Resources នៅក្នុង Namespace ជាក់លាក់

នៅពេលអ្នកប្រើ `kubectl get` ឬ `kubectl describe` អ្នកត្រូវបញ្ជាក់ Namespace ដោយប្រើ Flag `-n` ឬ `--namespace` ។

*   **មើល Pods នៅក្នុង `development` Namespace:**
    ```bash
    kubectl get pods -n development
    ```

*   **មើល Deployments នៅក្នុង `development` Namespace:**
    ```bash
    kubectl get deployments -n development
    ```

*   **មើល Resources ទាំងអស់នៅក្នុង Namespace ទាំងអស់ (រួមបញ្ចូល Column Namespace):**
    ```bash
    kubectl get all --all-namespaces
    ```

### ការផ្លាស់ប្តូរ Namespace លំនាំដើម (Default Namespace)

ប្រសិនបើអ្នកធ្វើការច្រើននៅក្នុង Namespace ជាក់លាក់មួយ អ្នកអាចកំណត់វាជា Default Namespace សម្រាប់ `kubectl` Context បច្ចុប្បន្នរបស់អ្នក។

1.  **មើល Contexts បច្ចុប្បន្ន:**
    ```bash
    kubectl config get-contexts
    ```

2.  **កំណត់ Namespace លំនាំដើមសម្រាប់ Current Context:**
    ```bash
    kubectl config set-context $(kubectl config current-context) --namespace=development
    ```
    *   **ការពន្យល់:** `$(kubectl config current-context)` នឹងទទួលបានឈ្មោះរបស់ Context ដែលអ្នកកំពុងប្រើបច្ចុប្បន្ន។

    ឥឡូវនេះ ប្រសិនបើអ្នកដំណើរការ `kubectl get pods` ដោយមិនបញ្ជាក់ `-n` វានឹងបង្ហាញ Pods នៅក្នុង `development` Namespace ។

### ការលុប Namespace

ការលុប Namespace នឹងលុប Resources ទាំងអស់ដែលស្ថិតនៅក្រោម Namespace នោះដោយស្វ័យប្រវត្តិ។ **ត្រូវប្រុងប្រយ័ត្នខ្ពស់នៅពេលលុប Namespace ជាពិសេសនៅក្នុង Production Environment!**

```bash
kubectl delete namespace development
```

### សរុបមក

Namespaces គឺជាគំនិតដ៏សំខាន់មួយនៅក្នុង Kubernetes សម្រាប់រៀបចំ និងគ្រប់គ្រង Resources នៅក្នុង Cluster ។ ពួកវាផ្តល់នូវវិធីសាស្រ្តមួយក្នុងការបែងចែក Cluster ទៅជា Virtual Clusters តូចៗ ដែលជួយសម្រួលដល់ការគ្រប់គ្រង, ការកំណត់សិទ្ធិ, និងការជៀសវាងជម្លោះឈ្មោះសម្រាប់ក្រុមការងារ និងកម្មវិធីផ្សេងៗគ្នា។