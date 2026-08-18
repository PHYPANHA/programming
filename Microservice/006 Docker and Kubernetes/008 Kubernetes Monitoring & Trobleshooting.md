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

# ជំពូកទី ៨៖ ការត្រួតពិនិត្យ និងការដោះស្រាយបញ្ហា (Monitoring & Troubleshooting)

## ៨.១ Logging (ការប្រមូល Logs)

នៅក្នុង Microservices Architecture ដែលមាន Pods និង Services ជាច្រើនកំពុងដំណើរការ វាមានសារៈសំខាន់ខ្លាំងណាស់ក្នុងការប្រមូល និងវិភាគ Logs ពីកម្មវិធីរបស់អ្នក។ Logs ផ្តល់នូវព័ត៌មានដ៏មានតម្លៃសម្រាប់ការ Debugging, ការត្រួតពិនិត្យ (Monitoring), និងការដោះស្រាយបញ្ហា (Troubleshooting) កម្មវិធីរបស់អ្នក។

### ហេតុអ្វីបានជា Logging សំខាន់ក្នុង Kubernetes?

*   **Ephemeral Nature របស់ Pods:** Pods គឺ Ephemeral ហើយអាចត្រូវបានលុបចោល ឬ Restart បានគ្រប់ពេល។ នៅពេល Pod ត្រូវបានលុប Logs ដែលបានរក្សាទុកនៅក្នុង Container's Filesystem ក៏នឹងបាត់បង់ដែរ។ ដូច្នេះយើងមិនអាចពឹងផ្អែកលើ Local Logs របស់ Container បានទេ។
*   **Distributed Systems:** កម្មវិធីត្រូវបានបំបែកទៅជា Microservices ជាច្រើន។ ការតាមដានលំហូររបស់ Request ឆ្លងកាត់ Services ផ្សេងៗគ្នាទាមទារនូវប្រព័ន្ធ Logging កណ្តាល។
*   **Debugging និង Troubleshooting:** នៅពេលមានបញ្ហា ការវិភាគ Logs គឺជាជំហានដំបូងក្នុងការស្វែងរកមូលហេតុ។
*   **Monitoring និង Alerting:** Logs អាចត្រូវបានប្រើដើម្បីបង្កើត Metrics និង Alerts សម្រាប់ស្ថានភាពកម្មវិធី។

### Logging នៅក្នុង Kubernetes (Standard Output និង Standard Error)

នៅក្នុង Kubernetes កម្មវិធីដែលដំណើរការនៅក្នុង Containers ត្រូវបានរចនាឡើងដើម្បីសរសេរ Logs របស់វាទៅកាន់ **`stdout` (Standard Output)** និង **`stderr` (Standard Error)** ។ Container Runtime (ឧទាហរណ៍ Docker, containerd) នឹងស្ទាក់ចាប់ Logs ទាំងនេះ ហើយបញ្ជូនវាទៅកាន់ Kubelet នៅលើ Node នោះ។ Kubelet បន្ទាប់មកនឹងបញ្ជូន Logs ទាំងនោះទៅកាន់ប្រព័ន្ធ Logging របស់ Node ។

#### ១. ការមើល Logs ដោយប្រើ `kubectl logs`

`kubectl logs` គឺជា Command ងាយស្រួលបំផុតសម្រាប់មើល Logs ពី Container នៅក្នុង Pod មួយ។

**ឧទាហរណ៍ Pod YAML (logging-app.yaml):**
   
    
```yaml
%%writefile logging-app.yaml
apiVersion: v1
kind: Pod
metadata:
  name: logging-app
spec:
  containers:
  - name: my-logger
    image: alpine:latest
    command: ["/bin/sh", "-c"]
    args:
      - while true; do
          echo "INFO: $(date) - This is an informational message.";
          echo "ERROR: $(date) - Something went wrong!" >&2;
          sleep 5;
        done
    ports:
    - containerPort: 80
```

``` yaml
# Deploy Pod
!kubectl apply -f logging-app.yaml

# រង់ចាំ Pod ដំណើរការ
!kubectl wait --for=condition=Ready pod/logging-app --timeout=60s
```

**មើល Logs របស់ Pod:**

```yaml
!kubectl logs logging-app
```

**មើល Logs ជាក់លាក់ (ឧទាហរណ៍ មើលតែ `stderr`):**

`kubectl logs` នឹងបង្ហាញទាំង `stdout` និង `stderr` រួមគ្នា។ អ្នកអាច Filter វាបានដោយប្រើ Tools ដូចជា `grep` ។

``` yaml
# មើល Logs ដែលមានតែពាក្យ 'ERROR'
!kubectl logs logging-app | grep ERROR
```

**តាមដាន Logs ក្នុងពេលជាក់ស្តែង (Follow Logs):**

```yaml
# ដើម្បីបញ្ឈប់ សូមចុច Ctrl+C
!kubectl logs -f logging-app
```

### Centralized Logging Solutions (ដំណោះស្រាយ Logging កណ្តាល)

ខណៈពេលដែល `kubectl logs` មានប្រយោជន៍សម្រាប់ការ Debugging បណ្តោះអាសន្ន វាត្រូវបានកំណត់ត្រឹម Logs របស់ Pod តែមួយ។ សម្រាប់ Production Environments អ្នកត្រូវការ **Centralized Logging Solution** ដើម្បីប្រមូល, រក្សាទុក, វិភាគ, និង Visualise Logs ពី Pods ទាំងអស់នៅក្នុង Cluster ។

ដំណោះស្រាយ Centralized Logging ដ៏ពេញនិយមរួមមាន:

1.  **Elastic Stack (ELK Stack):** Elasticsearch (Storage), Logstash (Ingestion), Kibana (Visualization) ។ ជាធម្មតាប្រើ Filebeat ឬ Fluentd ជា Log Collector នៅលើ Node ។
2.  **Grafana Loki:** ដំណោះស្រាយ Log Aggregation ដែលមានមូលដ្ឋានលើ Prometheus ។
3.  **Cloud-native Logging Services:** ដូចជា Google Cloud Logging, AWS CloudWatch Logs, Azure Monitor ។

#### របៀបដែល Centralized Logging ដំណើរការ:

*   **Log Collector Agent:** Agent មួយ (ឧទាហរណ៍ Fluentd, Filebeat, Logstash) ត្រូវបាន Deploy នៅលើ Node នីមួយៗ (ជា DaemonSet) ។
*   **Collect Logs:** Agent នេះប្រមូល Logs ពី `stdout` និង `stderr` របស់ Containers ទាំងអស់នៅលើ Node នោះ។
*   **Process and Forward:** Logs ត្រូវបាន Process (Filter, Parse, Enrich) ហើយបន្ទាប់មកត្រូវបានបញ្ជូនទៅកាន់ Centralized Storage (ឧទាហរណ៍ Elasticsearch) ។
*   **Analyze and Visualize:** អ្នកប្រើប្រាស់អាចស្វែងរក, វិភាគ, និង Visualize Logs នៅក្នុង Tool ដូចជា Kibana ឬ Grafana ។

### ឧទាហរណ៍: ការដំឡើង Fluentd ជា DaemonSet (សម្រាប់ Minikube)

Fluentd គឺជា Open-source Data Collector ដ៏ពេញនិយមសម្រាប់ Unified Logging Layer ។ យើងនឹង Deploy Fluentd ជា DaemonSet ដើម្បីប្រមូល Logs ពី Nodes ទាំងអស់នៅក្នុង Cluster ។

**១. បង្កើត Service Account, ClusterRole, និង ClusterRoleBinding សម្រាប់ Fluentd:**

Fluentd ត្រូវការសិទ្ធិដើម្បីអានព័ត៌មាន Pods និង Nodes ។

```yaml
%%writefile fluentd-rbac.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: fluentd
  namespace: default
---
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  name: fluentd
rules:
- apiGroups: [""]
  resources: ["pods", "namespaces"]
  verbs: ["get", "list", "watch"]
---
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: fluentd
roleRef:
  kind: ClusterRole
  name: fluentd
  apiGroup: rbac.authorization.k8s.io
subjects:
- kind: ServiceAccount
  name: fluentd
  namespace: default
  ```
  ```yaml
  !kubectl apply -f fluentd-rbac.yaml
  ```

  **២. Deploy Fluentd DaemonSet:**

DaemonSet នេះនឹង Deploy Pod Fluentd មួយនៅលើ Node នីមួយៗ។ Fluentd នឹង Mount `/var/log` របស់ Host Node ដើម្បីអាន Container Logs ។

``` yaml
%%writefile fluentd-daemonset.yaml
apiVersion: apps/v1
kind: DaemonSet
metadata:
  name: fluentd
  namespace: default
  labels:
    app: fluentd
spec:
  selector:
    matchLabels:
      app: fluentd
  template:
    metadata:
      labels:
        app: fluentd
    spec:
      serviceAccountName: fluentd
      tolerations:
      - key: node-role.kubernetes.io/control-plane
        operator: Exists
        effect: NoSchedule
      - key: node-role.kubernetes.io/master
        operator: Exists
        effect: NoSchedule
      containers:
      - name: fluentd
        image: fluent/fluentd-kubernetes-daemonset:v1.16-debian-elasticsearch
        env:
          - name: FLUENT_ELASTICSEARCH_HOST
            value: "elasticsearch-logging"
          - name: FLUENT_ELASTICSEARCH_PORT
            value: "9200"
          - name: FLUENT_ELASTICSEARCH_SCHEME
            value: "http"
          - name: FLUENT_ELASTICSEARCH_USER
            value: "fluentd"
          - name: FLUENT_ELASTICSEARCH_PASSWORD
            value: "changeme"
        resources:
          limits:
            memory: 200Mi
          requests:
            cpu: 100m
            memory: 200Mi
        volumeMounts:
        - name: varlog
          mountPath: /var/log
        - name: varlibdockercontainers
          mountPath: /var/lib/docker/containers
          readOnly: true
      volumes:
      - name: varlog
        hostPath:
          path: /var/log
      - name: varlibdockercontainers
        hostPath:
          path: /var/lib/docker/containers
```

**ចំណាំ:** Fluentd DaemonSet ខាងលើត្រូវបានកំណត់រចនាសម្ព័ន្ធដើម្បីបញ្ជូន Logs ទៅកាន់ Elasticsearch Server ឈ្មោះ `elasticsearch-logging` ។ សម្រាប់ Minikube យើងនឹងមិនដំឡើង Elasticsearch និង Kibana ពេញលេញនោះទេ ព្រោះវាទាមទារ Resources ច្រើន។ គោលបំណងគឺបង្ហាញពីរបៀបដែល Log Collector Agent ត្រូវបាន Deploy ។

```yaml
!kubectl apply -f fluentd-daemonset.yaml
```

**៣. ផ្ទៀងផ្ទាត់ Fluentd DaemonSet:**

```yaml
!kubectl get daemonset fluentd
!kubectl get pods -l app=fluentd
```

អ្នកគួរតែឃើញ Fluentd Pod កំពុងដំណើរការ។ Logs ពី `logging-app` របស់យើងនឹងត្រូវបានប្រមូលដោយ Fluentd ហើយព្យាយាមបញ្ជូនទៅកាន់ Elasticsearch ។ (អ្នកអាចមើល Logs របស់ Fluentd Pod ដើម្បីមើល Process របស់វា)។

### Best Practices សម្រាប់ Logging ក្នុង Kubernetes

*   **សរសេរទៅ `stdout`/`stderr`:** កម្មវិធីរបស់អ្នកគួរតែសរសេរ Logs ទៅកាន់ `stdout` និង `stderr` ជានិច្ច។
*   **Structured Logging:** ប្រើ Structured Logging (ឧទាហរណ៍ JSON format) ដើម្បីងាយស្រួលក្នុងការ Parsing និង Query Logs ។
*   **Logging Level:** ប្រើ Logging Levels ដែលសមរម្យ (INFO, DEBUG, WARN, ERROR) ។
*   **Contextual Logging:** បន្ថែម Contextual Information ទៅកាន់ Logs (ឧទាហរណ៍ Request ID, User ID) ដើម្បីជួយក្នុងការ Tracing ។
*   **Centralized Logging:** ប្រើ Centralized Logging Solution សម្រាប់ Production Workloads ។

### សរុបមក

Logging គឺជាផ្នែកដ៏សំខាន់មួយនៃ Monitoring និង Troubleshooting កម្មវិធីនៅក្នុង Kubernetes ។ ការយល់ដឹងពីរបៀបដែល Kubernetes គ្រប់គ្រង Logs និងការអនុវត្ត Centralized Logging Solution គឺជាគន្លឹះក្នុងការធានានូវ Observability និង Reliability របស់កម្មវិធីរបស់អ្នក។

```yaml
# Clean up
!kubectl delete -f logging-app.yaml
!kubectl delete -f fluentd-rbac.yaml
!kubectl delete -f fluentd-daemonset.yaml

!rm logging-app.yaml fluentd-rbac.yaml fluentd-daemonset.yaml
```

## ៨.២ Monitoring & Metrics (ការត្រួតពិនិត្យ និង Metrics)

ការត្រួតពិនិត្យ (Monitoring) គឺជាផ្នែកដ៏សំខាន់មួយទៀតក្នុងការគ្រប់គ្រង Kubernetes Cluster និងកម្មវិធីរបស់អ្នក។ ខណៈពេលដែល Logs ប្រាប់អ្នកពីអ្វីដែលបានកើតឡើង, Metrics ប្រាប់អ្នកពីរបៀបដែលប្រព័ន្ធរបស់អ្នកកំពុងដំណើរការ (How your system is performing)។ Metrics ផ្តល់នូវទិន្នន័យលេខអំពី Resource Usage (CPU, Memory, Network, Disk), Performance (Latency, Throughput), និង Health របស់ Components ផ្សេងៗនៅក្នុង Cluster ។

### ហេតុអ្វីបានជា Metrics សំខាន់ក្នុង Kubernetes?

*   **Performance Tracking:** តាមដាន Performance របស់កម្មវិធី និង Infrastructure ដើម្បីរកមើល Bottlenecks ។
*   **Resource Optimization:** ជួយក្នុងការបែងចែក Resources (CPU, Memory) ប្រកបដោយប្រសិទ្ធភាព ដើម្បីកាត់បន្ថយការចំណាយ និងបង្កើនការប្រើប្រាស់។
*   **Alerting and Anomaly Detection:** កំណត់ Alerts នៅពេល Metrics លើសពី Thresholds ដែលបានកំណត់ ឬនៅពេលមានឥរិយាបថមិនប្រក្រតី។
*   **Scaling Decisions:** ផ្តល់ទិន្នន័យសម្រាប់ Automated Scaling (ឧទាហរណ៍ Horizontal Pod Autoscaler) ។
*   **Capacity Planning:** ជួយក្នុងការរៀបចំផែនការសម្រាប់តម្រូវការ Resource នាពេលអនាគត។

### Kubernetes Metrics API និង Metrics Server

Kubernetes ផ្តល់នូវ Metrics API ដែលអនុញ្ញាតឱ្យអ្នក Query Resource Usage របស់ Nodes និង Pods ។ Metrics API នេះត្រូវបានផ្តល់ជូនដោយ **Metrics Server** ។

**Metrics Server** គឺជា Aggregator នៃទិន្នន័យ Resource Usage ដែលប្រមូល Metrics ពី Kubelet នៅលើ Node នីមួយៗ (Kubelet មាន cAdvisor ដែលប្រមូល Metrics ពី Containers) ។ វាត្រូវបានប្រើប្រាស់ដោយ Commands ដូចជា `kubectl top` និងដោយ Features ដូចជា Horizontal Pod Autoscaler (HPA) ។

### ការដំឡើង និងពិនិត្យ Metrics Server (នៅលើ Minikube)

នៅលើ Minikube, Metrics Server ជាធម្មតាត្រូវបានដំឡើងជា Addon ។ អ្នកអាចពិនិត្យមើល Status របស់វា។

```yaml
# ពិនិត្យមើលថាតើ metrics-server កំពុងដំណើរការឬអត់
print("Checking for metrics-server pods...")
!kubectl get pods -n kube-system -l k8s-app=metrics-server

# ប្រសិនបើវាមិនដំណើរការ (0 Pods ឬ Status មិនមែន Running) អ្នកអាច Enable វាដោយប្រើ Minikube addon
# !minikube addons enable metrics-server
# !kubectl wait --for=condition=Ready pod -l k8s-app=metrics-server -n kube-system --timeout=120s
print("\nIf metrics-server is not running, you might need to enable it with: `minikube addons enable metrics-server`")
```

```yaml
### Deploy Sample Application ដើម្បីបង្កើត Metrics

ដើម្បីឱ្យ `kubectl top` បង្ហាញ Metrics យើងត្រូវការ Pods ដែលកំពុងដំណើរការ និងប្រើប្រាស់ Resources ។ យើងនឹង Deploy Nginx Deployment មួយ។
```

```yaml
%%writefile nginx-metrics-deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-metrics-app
  labels:
    app: nginx-metrics
spec:
  replicas: 2
  selector:
    matchLabels:
      app: nginx-metrics
  template:
    metadata:
      labels:
        app: nginx-metrics
    spec:
      containers:
      - name: nginx-container
        image: nginx:latest
        ports:
        - containerPort: 80
        resources: # កំណត់ requests និង limits ដើម្បីឱ្យ metrics server អាច report បាន
          requests:
            memory: "64Mi"
            cpu: "100m"
          limits:
            memory: "128Mi"
            cpu: "200m"

!kubectl apply -f nginx-metrics-deployment.yaml
!kubectl wait --for=condition=Ready pod -l app=nginx-metrics --timeout=120s
```

ឥឡូវនេះយើងនឹងប្រើ Command `kubectl top` ដើម្បីមើល Metrics របស់ Nodes និង Pods ។

### ការមើល Metrics ជាមួយ `kubectl top`

#### ១. មើល Metrics របស់ Nodes

```yaml
# មើល CPU និង Memory Usage របស់ Nodes
!kubectl top nodes
```

**ការពន្យល់:** Output នេះបង្ហាញពីការប្រើប្រាស់ CPU និង Memory របស់ Node នីមួយៗនៅក្នុង Cluster ។ នេះមានប្រយោជន៍សម្រាប់ការមើលថា Node ណាមួយកំពុងត្រូវបានប្រើប្រាស់ច្រើន ឬតិច។

#### ២. មើល Metrics របស់ Pods
```yaml
# មើល CPU និង Memory Usage របស់ Pods នៅក្នុង Namespace បច្ចុប្បន្ន
!kubectl top pods
```

**ការពន្យល់:** Output នេះបង្ហាញពីការប្រើប្រាស់ CPU និង Memory របស់ Pod នីមួយៗ។ នេះជួយអ្នកឱ្យយល់ថា Pod ណាមួយកំពុងស៊ី Resources ច្រើន ហើយអាចត្រូវការ Resource Allocation បន្ថែម ឬ Optimization ។

#### ៣. មើល Metrics របស់ Pods នៅក្នុង Namespace ទាំងអស់`

```yaml
# មើល CPU និង Memory Usage របស់ Pods នៅក្នុង Namespace ទាំងអស់
!kubectl top pods --all-namespaces
```

**ការពន្យល់:** Command នេះជួយអ្នកឱ្យមើលឃើញទិដ្ឋភាពទូទៅនៃ Resource Usage របស់ Pods ទាំងអស់នៅក្នុង Cluster ។

### សរុបមក

Metrics គឺជាទិន្នន័យដ៏សំខាន់មួយសម្រាប់វិភាគ Performance និង Health របស់ Kubernetes Cluster និងកម្មវិធីរបស់អ្នក។ `metrics-server` ផ្តល់នូវ Metrics API ដែល `kubectl top` ប្រើដើម្បីផ្តល់ឱ្យអ្នកនូវព័ត៌មានអំពី Resource Usage របស់ Nodes និង Pods ។ សម្រាប់ដំណោះស្រាយ Monitoring ដ៏ទូលំទូលាយបន្ថែមទៀត អ្នកអាចពិចារណាប្រើប្រាស់ Tools ដូចជា Prometheus សម្រាប់ការប្រមូល Metrics និង Grafana សម្រាប់ការ Visualization ។ Metrics ទាំងនេះក៏ជាមូលដ្ឋានគ្រឹះសម្រាប់ Features ស្វ័យប្រវត្តិកម្មដូចជា Horizontal Pod Autoscaler ផងដែរ។

# Clean up
!kubectl delete -f nginx-metrics-deployment.yaml
!rm nginx-metrics-deployment.yaml

## ៨.៣ Advanced Monitoring (Prometheus & Grafana)

ខណៈពេលដែល `kubectl top` ផ្តល់នូវទិដ្ឋភាពទូទៅយ៉ាងរហ័សនៃ Resource Usage, សម្រាប់ Production Environment អ្នកត្រូវការដំណោះស្រាយ Monitoring ដ៏ទូលំទូលាយ ដែលអាចប្រមូល, រក្សាទុក, Query, និង Visualise Metrics ក្នុងរយៈពេលវែង។ **Prometheus** និង **Grafana** គឺជាបន្សំដ៏ពេញនិយមបំផុតសម្រាប់គោលបំណងនេះនៅក្នុង Kubernetes ។

### ១. Prometheus

**Prometheus** គឺជា Open-source System Monitoring និង Alerting Toolkit ដែលត្រូវបានបង្កើតឡើងដំបូងនៅ SoundCloud ។ វាបានក្លាយជាស្តង់ដារជាក់ស្តែង (de facto standard) សម្រាប់ Monitoring Kubernetes Clusters ។

**របៀបដែល Prometheus ដំណើរការ:**
*   **Pull Model:** Prometheus ប្រមូល Metrics ពី Target ដែលបានកំណត់រចនាសម្ព័ន្ធ (ឧទាហរណ៍ Kubernetes Components, Pods របស់កម្មវិធី) ដោយធ្វើ HTTP Pull Request ទៅកាន់ `/metrics` Endpoint ។
*   **Time-series Database:** វាផ្ទុក Metrics ទាំងនេះនៅក្នុង Time-series Database របស់វា ដែលអាច Query បានដោយប្រើ PromQL (Prometheus Query Language) ។
*   **Discovery:** Prometheus អាចស្វែងរក Targets ដោយស្វ័យប្រវត្តិនៅក្នុង Kubernetes Cluster ។

### ២. Grafana

**Grafana** គឺជា Open-source Analytics និង Interactive Visualization Web Application ។ វាអនុញ្ញាតឱ្យអ្នក Query, Visualize, Alert លើ Metrics មិនថា Metrics របស់អ្នកត្រូវបានរក្សាទុកនៅទីណាទេ (Prometheus គឺជា Data Source ដ៏ពេញនិយមមួយសម្រាប់ Grafana) ។

**មុខងារសំខាន់ៗរបស់ Grafana:**
*   **Dashboards:** បង្កើត Dashboards ដ៏ស្រស់ស្អាត និងអាចប្ដូរតាមបំណង ដើម្បីបង្ហាញ Metrics ។
*   **Data Sources:** គាំទ្រ Data Sources ជាច្រើន (Prometheus, Elasticsearch, InfluxDB, CloudWatch, ល) ។
*   **Alerting:** កំណត់ Alerts ដោយផ្អែកលើ Thresholds របស់ Metrics ។

### ការដំឡើង Prometheus និង Grafana (នៅលើ Minikube)

វិធីងាយស្រួលបំផុតដើម្បីដំឡើង Prometheus និង Grafana នៅលើ Minikube គឺប្រើ Helm ។ Helm គឺជា Package Manager សម្រាប់ Kubernetes ។

#### ជំហានទី ១: ដំឡើង Helm

ប្រសិនបើអ្នកមិនទាន់បានដំឡើង Helm ទេ អ្នកអាចដំឡើងវាដោយប្រើ Command ខាងក្រោម៖

```yaml
# សម្រាប់ Linux/macOS
# curl -fsSL https://raw.githubusercontent.com/helm/helm/main/scripts/get-helm-3 | bash

# ពិនិត្យមើល Version របស់ Helm
print("Checking Helm version...")
!helm version
```

#### ជំហានទី ២: បន្ថែម Prometheus Community Helm Repository

យើងនឹងបន្ថែម Helm Repository ដែលមាន Prometheus និង Grafana Charts ។

```yaml
!helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
!helm repo update
```

#### ជំហានទី ៣: ដំឡើង Prometheus Stack

យើងនឹងដំឡើង `kube-prometheus-stack` Chart ដែលរួមបញ្ចូល Prometheus, Grafana, Alertmanager, និង Exporters ផ្សេងៗទៀត។

**ចំណាំ:** ការដំឡើងនេះត្រូវការ Resource ច្រើនជាងធម្មតា។ សូមប្រាកដថា Minikube របស់អ្នកមាន RAM និង CPU គ្រប់គ្រាន់ (យ៉ាងហោចណាស់ 4GB RAM, 2 CPU Cores) ។

# បង្កើត Namespace សម្រាប់ Monitoring
!kubectl create namespace monitoring

# ដំឡើង Prometheus Stack
!helm install prometheus prometheus-community/kube-prometheus-stack --namespace monitoring --set grafana.adminPassword='admin' --set grafana.service.type=NodePort --set prometheus.service.type=NodePort

#### ជំហានទី ៤: រង់ចាំ Pods ដំណើរការ

ការដំឡើងនេះអាចចំណាយពេលពីរបីនាទី។

```yaml
!kubectl get pods -n monitoring --watch
```

### ការ Access Grafana Dashboard

នៅពេល Pods ទាំងអស់ដំណើរការ អ្នកអាច Access Grafana Dashboard ។

```yaml
# ស្វែងរក IP Address របស់ Minikube Node
MINIKUBE_IP=$(minikube ip)

# ទទួលបាន Grafana NodePort
GRAFANA_NODEPORT=$(kubectl get svc prometheus-grafana -n monitoring -o jsonpath='{.spec.ports[0].nodePort}')

GRAFANA_URL="http://${MINIKUBE_IP}:${GRAFANA_NODEPORT}"

print(f"Grafana Dashboard URL: {GRAFANA_URL}")
print("Username: admin")
print("Password: admin")
```

**របៀប Access Grafana:**

1.  បើក Browser របស់អ្នកហើយចូលទៅកាន់ URL ដែលបានបង្ហាញ (ឧទាហរណ៍ `http://192.168.49.2:3xxxx`) ។
2.  បញ្ចូល Username: `admin` និង Password: `admin` ។
3.  អ្នកគួរតែឃើញ Grafana Dashboard ។ អ្នកអាចរុករក Dashboards ដែលបានផ្តល់ជូនរួចជាស្រេចសម្រាប់ Kubernetes (ឧទាហរណ៍ 'Kubernetes / Compute Resources / Namespace (Pods)') ។

### ការ Access Prometheus UI (សម្រាប់អ្នកចង់ដឹងបន្ថែម)

អ្នកក៏អាច Access Prometheus UI ដោយផ្ទាល់ ដើម្បី Query Metrics ដោយប្រើ PromQL ។

```yaml
# ទទួលបាន Prometheus NodePort
PROMETHEUS_NODEPORT=$(kubectl get svc prometheus-kube-prometheus-prometheus -n monitoring -o jsonpath='{.spec.ports[0].nodePort}')

PROMETHEUS_URL="http://${MINIKUBE_IP}:${PROMETHEUS_NODEPORT}"

print(f"Prometheus UI URL: {PROMETHEUS_URL}")
```

**របៀប Access Prometheus:**

1.  បើក Browser របស់អ្នកហើយចូលទៅកាន់ URL ដែលបានបង្ហាញ (ឧទាហរណ៍ `http://192.168.49.2:3xxxx`) ។
2.  អ្នកអាចសាកល្បង Query មួយចំនួនដូចជា `node_cpu_seconds_total` ឬ `kube_pod_info` នៅក្នុងរបារ 'Expression' ។

### សរុបមក

Prometheus និង Grafana គឺជា Tools ដ៏សំខាន់សម្រាប់ Monitoring Kubernetes Clusters ។ Prometheus ប្រមូល Time-series Metrics ពី Components ទាំងអស់នៃ Cluster រីឯ Grafana ផ្តល់នូវ Dashboards ដ៏មានឥទ្ធិពលសម្រាប់ការ Visualization និង Analysis ។ ការរួមបញ្ចូលគ្នានៃ Tools ទាំងពីរនេះផ្តល់ឱ្យអ្នកនូវ Observability ពេញលេញទៅក្នុង Performance និង Health របស់កម្មវិធី និង Infrastructure របស់អ្នក។

យើងបានបញ្ចប់ជំពូកទី ៨៖ ការត្រួតពិនិត្យ និងការដោះស្រាយបញ្ហា (Monitoring & Troubleshooting)។

```yaml
# Clean up (លុប Prometheus Stack និង Namespace)
!helm uninstall prometheus --namespace monitoring
!kubectl delete namespace monitoring
```
