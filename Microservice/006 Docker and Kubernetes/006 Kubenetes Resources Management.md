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

# ជំពូកទី ៦៖ ការគ្រប់គ្រង Resources (Resource Management)

នៅក្នុង Kubernetes Cluster ការគ្រប់គ្រង Resource (CPU, Memory) គឺជាកត្តាសំខាន់ដើម្បីធានាថាកម្មវិធីរបស់អ្នកដំណើរការបានល្អប្រសើរ និងដើម្បីទាញយកអត្ថប្រយោជន៍ពេញលេញពី Infrastructure របស់អ្នក។

## ៦.១ Resource Requests និង Limits (CPU & Memory)

នៅពេលអ្នក Deploy កម្មវិធីទៅកាន់ Kubernetes Pods អ្នកអាចបញ្ជាក់ពីចំនួន Resource (CPU និង Memory) ដែល Container នីមួយៗត្រូវការ។ នេះមានសារៈសំខាន់ណាស់សម្រាប់ Kubernetes Scheduler ដើម្បីសម្រេចចិត្តថា Pod គួរត្រូវបានដាក់ឱ្យដំណើរការនៅលើ Node មួយណា និងសម្រាប់ Kubelet ដើម្បីគ្រប់គ្រង Resource Allocation នៅលើ Node នោះ។

Kubernetes ប្រើ Concepts ពីរសម្រាប់ Resource Management គឺ **Requests** និង **Limits** ។

### ១. Requests (សំណើ)

**Resource Request** គឺជាចំនួន Resource អប្បបរមាដែល Container ត្រូវការ។ Scheduler របស់ Kubernetes ប្រើ Requests ទាំងនេះដើម្បីជ្រើសរើស Node ដែលមាន Resource គ្រប់គ្រាន់សម្រាប់ Pod របស់អ្នក។ ប្រសិនបើ Node មិនមាន Resource គ្រប់គ្រាន់ដើម្បីបំពេញ Request របស់ Pod នោះ Pod នឹងមិនត្រូវបាន Schedule ទៅកាន់ Node នោះទេ។

*   **សម្រាប់ CPU:** Request គឺជារង្វាស់នៃ CPU time ដែលត្រូវបានធានាសម្រាប់ Container ។
*   **សម្រាប់ Memory:** Request គឺជាចំនួន Memory ដែលត្រូវបានធានាសម្រាប់ Container ។

### ២. Limits (ដែនកំណត់)

**Resource Limit** គឺជាចំនួន Resource អតិបរមាដែល Container ត្រូវបានអនុញ្ញាតឱ្យប្រើប្រាស់។

*   **សម្រាប់ CPU:** ប្រសិនបើ Container ព្យាយាមប្រើ CPU លើសពី Limit ដែលបានកំណត់ នោះ CPU time របស់វាអាចត្រូវបានកាត់បន្ថយ (throttled) ។ Container នឹងមិនត្រូវបាន Kill នោះទេ គ្រាន់តែត្រូវបានកំណត់ល្បឿន។
*   **សម្រាប់ Memory:** ប្រសិនបើ Container ព្យាយាមប្រើ Memory លើសពី Limit ដែលបានកំណត់ នោះ Container នឹងត្រូវបាន Kill ដោយប្រព័ន្ធ (OOMKilled - Out Of Memory Killed) ហើយបន្ទាប់មកអាចត្រូវបាន Restart ដោយ Kubelet ។

### ហេតុអ្វីត្រូវប្រើ Requests និង Limits?

*   **ធានា Performance (Requests):** ធានាថាកម្មវិធីរបស់អ្នកនឹងមាន Resource គ្រប់គ្រាន់ដើម្បីដំណើរការដោយរលូន។
*   **ការពារ Node ពី Overload (Limits):** ការពារ Container មួយពីការស៊ី Resource ទាំងអស់របស់ Node ដែលអាចប៉ះពាល់ដល់ Containers ផ្សេងទៀតដែលកំពុងដំណើរការនៅលើ Node ដូចគ្នា។
*   **បង្កើន Resource Utilization:** អនុញ្ញាតឱ្យ Scheduler ដាក់ Pods ជាច្រើននៅលើ Node មួយដោយដឹងថា Resource ត្រូវបានបែងចែកយ៉ាងត្រឹមត្រូវ។

*   **CPU:** រង្វាស់របស់ CPU គឺ **cores** ឬ **millicores** (m) ។ `1000m` ស្មើនឹង `1` core ។ ឧទាហរណ៍ `500m` គឺ 0.5 core ឬពាក់កណ្តាលនៃ CPU core មួយ។
*   **Memory:** រង្វាស់របស់ Memory គឺ **bytes** ។ អ្នកអាចប្រើ Suffix ដូចជា `Mi` (mebibytes) ឬ `Gi` (gibibytes) ។ ឧទាហរណ៍ `256Mi` (256 megabytes) ឬ `2Gi` (2 gigabytes) ។

### ឧទាហរណ៍ Pod YAML ជាមួយ Requests និង Limits

ខាងក្រោមនេះគឺជា Pod Definition សម្រាប់ Nginx Container ដែលបានកំណត់ Requests និង Limits សម្រាប់ CPU និង Memory។
```yaml
%%writefile nginx-pod-with-resources.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod-with-resources
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
    resources: # កំណត់ Resource Requests និង Limits
      requests:
        memory: "128Mi"
        cpu: "200m" # 0.2 នៃ CPU core
      limits:
        memory: "256Mi"
        cpu: "400m" # 0.4 នៃ CPU core
    ports:
    - containerPort: 80
```
**ការពន្យល់:**
*   Container នេះ **ស្នើសុំ (requests)** Memory 128 MiB និង CPU 200 millicores ។ Scheduler នឹងស្វែងរក Node ដែលមាន Resource ទំនេរយ៉ាងហោចណាស់ប៉ុណ្ណឹង។
*   Container នេះ **កំណត់ដែនកំណត់ (limits)** Memory 256 MiB និង CPU 400 millicores ។ ប្រសិនបើវាព្យាយាមប្រើលើសពីនេះ វានឹងត្រូវបាន Throttled សម្រាប់ CPU ឬ Kill សម្រាប់ Memory ។

### Deploy និងផ្ទៀងផ្ទាត់

```yaml
# Deploy Pod
!kubectl apply -f nginx-pod-with-resources.yaml
```

ពិនិត្យមើល Status របស់ Pod:

```yaml
!kubectl get pod nginx-pod-with-resources
```

ដើម្បីមើលព័ត៌មានលម្អិតអំពី Resource Requests និង Limits សម្រាប់ Pod នេះ:

```yaml
!kubectl describe pod nginx-pod-with-resources
```

អ្នកគួរតែឃើញផ្នែក `Resources` នៅក្នុង Output ដែលបង្ហាញពី Requests និង Limits ដែលបានកំណត់។

### Quality of Service (QoS) Classes

Kubernetes កំណត់ Quality of Service (QoS) Class សម្រាប់ Pod នីមួយៗដោយផ្អែកលើ Resource Requests និង Limits ដែលបានកំណត់។ QoS Classes ទាំងនេះជួយ Kubernetes ក្នុងការបែងចែក Resource និងធ្វើការសម្រេចចិត្តនៅពេលមាន Resource Shortage ។

មាន ៣ ប្រភេទគឺ:

1.  **Guaranteed:**
    *   **លក្ខខណ្ឌ:** Container ទាំងអស់នៅក្នុង Pod ត្រូវតែកំណត់ Request និង Limit សម្រាប់ CPU និង Memory ហើយតម្លៃ Requests ត្រូវតែស្មើនឹង Limits ។
    *   **អត្ថប្រយោជន៍:** ផ្តល់នូវកម្រិត Performance ខ្ពស់បំផុត។ Pods ទាំងនេះទំនងជានឹងមិនត្រូវបាន Kill (evicted) ដោយសារតែ Resource Shortage នោះទេ។

2.  **Burstable:**
    *   **លក្ខខណ្ឌ:** Container យ៉ាងហោចណាស់មួយនៅក្នុង Pod មាន Resource Request (សម្រាប់ CPU ឬ Memory) ប៉ុន្តែមិនបានកំណត់ Limit ឬ Request មិនស្មើនឹង Limit ។
    *   **អត្ថប្រយោជន៍:** អាចប្រើ Resource លើសពី Request របស់វា រហូតដល់ Limit ។ នឹងត្រូវបាន Kill មុន Pods ប្រភេទ Guaranteed ប្រសិនបើមាន Resource Shortage ។

3.  **BestEffort:**
    *   **លក្ខខណ្ឌ:** Container ណាមួយនៅក្នុង Pod មិនបានកំណត់ Request ឬ Limit សម្រាប់ CPU ឬ Memory ។
    *   **អត្ថប្រយោជន៍:** មិនមានការធានា Resource នោះទេ ហើយនឹងត្រូវបាន Kill មុនគេនៅពេលមាន Resource Shortage ។

ការកំណត់ Requests និង Limits ឱ្យបានត្រឹមត្រូវគឺជាការអនុវត្តដ៏ល្អបំផុតដើម្បីធានាស្ថិរភាព (stability) និងប្រសិទ្ធភាព (efficiency) នៃ Cluster របស់អ្នក។

```yaml
# លុប Pod
!kubectl delete -f nginx-pod-with-resources.yaml
```
## ៦.២ Resource Quotas (ការកំណត់កូតា Resource)

Resource Quotas គឺជាយន្តការមួយនៅក្នុង Kubernetes ដែលអនុញ្ញាតឱ្យ Administrator កំណត់ដែនកំណត់ (limit) ទៅលើ Resource Consumption (CPU, Memory, ចំនួន Pods, Services ជាដើម) សម្រាប់ Namespace ជាក់លាក់មួយ។ នេះមានសារៈសំខាន់ខ្លាំងណាស់ក្នុងការធានាថា ក្រុមការងារ ឬកម្មវិធីមួយមិនអាចប្រើប្រាស់ Resource លើសពីកម្រិតដែលបានបែងចែកឱ្យវា ដែលអាចប៉ះពាល់ដល់ក្រុមការងារ ឬកម្មវិធីផ្សេងទៀតនៅក្នុង Cluster តែមួយ។

### ហេតុអ្វីត្រូវប្រើ Resource Quotas?

*   **ការបែងចែក Resource ដោយយុត្តិធម៌:** ធានាថា Resource របស់ Cluster ត្រូវបានបែងចែកស្មើភាពគ្នាទៅកាន់ក្រុមការងារ ឬ Projects ផ្សេងៗគ្នា។
*   **ការការពារ Over-consumption:** ការពារ Namespace មួយពីការប្រើប្រាស់ Resource ច្រើនពេក ដែលអាចបណ្តាលឱ្យ Cluster ទាំងមូលមានបញ្ហា Performance ។
*   **ការអនុវត្ត Policy:** អនុញ្ញាតឱ្យ Administrator អនុវត្ត Policy លើ Resource Usage ។
### អ្វីដែល Resource Quotas អាចកំណត់ដែនកំណត់

Resource Quotas អាចកំណត់ដែនកំណត់លើប្រភេទ Resource ជាច្រើនដូចជា:

*   **Computational Resources:**
    *   `limits.cpu`, `limits.memory`
    *   `requests.cpu`, `requests.memory`
*   **Storage Resources:**
    *   `requests.storage`
    *   `persistentvolumeclaims` (ចំនួន PVCs)
*   **Object Count:**
    *   `pods` (ចំនួន Pods)
    *   `replicationcontrollers`, `replicasets`, `deployments` (ចំនួន Objects ទាំងនេះ)
    *   `services` (ចំនួន Services)
    *   `configmaps`, `secrets` (ចំនួន Objects ទាំងនេះ)

### ឧទាហរណ៍ ResourceQuota YAML

ខាងក្រោមនេះគឺជាឧទាហរណ៍នៃ Resource Quota ដែលកំណត់ដែនកំណត់សម្រាប់ Namespace `dev-team` ។

```yaml
%%writefile dev-team-quota.yaml
apiVersion: v1
kind: ResourceQuota # ប្រភេទ Resource គឺ ResourceQuota
metadata:
  name: dev-team-resource-quota
  namespace: dev-team # កំណត់សម្រាប់ Namespace 'dev-team'
spec:
  hard: # កំណត់ដែនកំណត់អតិបរមា
    pods: "10" # អតិបរមា 10 Pods
    requests.cpu: "2" # សំណើ CPU សរុបអតិបរមា 2 Cores
    requests.memory: "4Gi" # សំណើ Memory សរុបអតិបរមា 4 GiB
    limits.cpu: "4" # ដែនកំណត់ CPU សរុបអតិបរមា 4 Cores
    limits.memory: "8Gi" # ដែនកំណត់ Memory សរុបអតិបរមា 8 GiB
    persistentvolumeclaims: "5" # អតិបរមា 5 PersistentVolumeClaims
    requests.storage: "10Gi" # សំណើ Storage សរុបអតិបរមា 10 GiB
```

**ការពន្យល់:**
*   `metadata.namespace: dev-team`: Resource Quota នេះនឹងត្រូវបានអនុវត្តទៅលើ `dev-team` Namespace ។
*   `spec.hard`: កំណត់ដែនកំណត់អតិបរមា (hard limits) សម្រាប់ Resource នីមួយៗ។
    *   Namespace នេះអាចមាន Pods យ៉ាងច្រើនបំផុត `10` ។
    *   ផលបូកនៃ `requests.cpu` សម្រាប់ Pods ទាំងអស់នៅក្នុង Namespace នេះមិនអាចលើសពី `2` Cores ទេ។
    *   ផលបូកនៃ `limits.memory` សម្រាប់ Pods ទាំងអស់នៅក្នុង Namespace នេះមិនអាចលើសពី `8Gi` ទេ។

### Deploy និងផ្ទៀងផ្ទាត់

១. **បង្កើត Namespace `dev-team`:**
```yaml
!kubectl create namespace dev-team
```

២. **Deploy Resource Quota:**
```yaml
!kubectl apply -f dev-team-quota.yaml
```

៣. **ពិនិត្យមើល Resource Quota:**

```yaml
!kubectl get resourcequota dev-team-resource-quota -n dev-team
```

អ្នកគួរតែឃើញ Output ដែលបង្ហាញពីដែនកំណត់ (`Hard`) និង Resource ដែលបានប្រើប្រាស់បច្ចុប្បន្ន (`Used`) ។

### សាកល្បង Resource Quotas

ឥឡូវនេះយើងនឹងព្យាយាម Deploy Pod មួយទៅកាន់ `dev-team` Namespace ដែលមាន Requests និង Limits ។
```yaml
%%writefile nginx-pod-for-dev-team.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-test-pod
  namespace: dev-team
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
    resources:
      requests:
        memory: "256Mi"
        cpu: "500m"
      limits:
        memory: "512Mi"
        cpu: "1"
```

១. **Deploy Pod ធម្មតា (នឹងជោគជ័យ):**

```yaml
!kubectl apply -f nginx-pod-for-dev-team.yaml
```

២. **ពិនិត្យ Quota ម្តងទៀត:**
```yaml
!kubectl get resourcequota dev-team-resource-quota -n dev-team
```
អ្នកគួរតែឃើញ `Used` Values ត្រូវបាន Update ។

៣. **ព្យាយាម Deploy Pod មួយទៀតដែលនឹងលើសពី Quota (ឧទាហរណ៍ CPU Requests):**

```yaml
%%writefile nginx-pod-exceed-quota.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-exceed-quota-pod
  namespace: dev-team
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
    resources:
      requests:
        memory: "256Mi"
        cpu: "1.8" # 1.8 Cores. Combined with first pod's 0.5 Cores, this is 2.3 Cores, exceeding the quota of 2 Cores.
      limits:
        memory: "512Mi"
        cpu: "2"
```

```yaml
!kubectl apply -f nginx-pod-exceed-quota.yaml
```

អ្នកគួរតែឃើញ Error មួយដែលបញ្ជាក់ថា Pod មិនអាចត្រូវបានបង្កើតដោយសារតែ Resource Quota (`exceeded quota: dev-team-resource-quota, requested: requests.cpu=1.8, used: requests.cpu=500m, limited: requests.cpu=2`).

### សរុបមក

Resource Quotas គឺជាឧបករណ៍ដ៏សំខាន់សម្រាប់ Administrator ក្នុងការគ្រប់គ្រង និងបែងចែក Resource នៅក្នុង Kubernetes Cluster របស់ពួកគេ។ តាមរយៈការកំណត់ដែនកំណត់លើ Resource Consumption សម្រាប់ Namespace នីមួយៗ Resource Quotas ជួយធានានូវ Stability, Fairness, និង Operational Efficiency នៃ Cluster ។ វាក៏ជួយលើកទឹកចិត្តដល់ Developers ឱ្យសរសេរ Code ដែលមានប្រសិទ្ធភាព និងកំណត់ Resource Requests/Limits ឱ្យបានត្រឹមត្រូវសម្រាប់កម្មវិធីរបស់ពួកគេ។

```yaml
# លុប Pods និង Resource Quota, Namespace
!kubectl delete -f nginx-pod-for-dev-team.yaml
!kubectl delete -f nginx-pod-exceed-quota.yaml
!kubectl delete -f dev-team-quota.yaml
!kubectl delete namespace dev-team
```

## ៦.៣ Limit Ranges (ការកំណត់ដែនកំណត់ Resource លំនាំដើម)

ខណៈពេលដែល Resource Quotas ផ្តល់នូវដែនកំណត់លើ Resource Usage សម្រាប់ Namespace មួយទាំងមូល **Limit Ranges** ផ្តល់នូវវិធីមួយដើម្បីកំណត់ដែនកំណត់ Resource លំនាំដើម (default) ឬដែនកំណត់អប្បបរមា/អតិបរមាសម្រាប់ Pods ឬ Containers នីមួយៗនៅក្នុង Namespace នោះ។

### អ្វីទៅជា Limit Range?

**Limit Range** គឺជា Object នៅក្នុង Kubernetes ដែលកំណត់ Constraint (ដែនកំណត់) លើ Resource Consumption សម្រាប់ Pods, Containers, ឬ PersistentVolumeClaims នៅក្នុង Namespace មួយ។

### ហេតុអ្វីត្រូវប្រើ Limit Ranges?

*   **កំណត់ Default Values:** ធានាថា Pods ទាំងអស់ដែលត្រូវបានបង្កើតនៅក្នុង Namespace មួយនឹងមាន Resource Requests និង Limits លំនាំដើម ទោះបីជា Developer មិនបានបញ្ជាក់វាក៏ដោយ។ នេះជួយជៀសវាង Pods ដែលមិនមាន Resource Limits ដែលអាចប៉ះពាល់ដល់ Cluster ទាំងមូល។
*   **កំណត់ Min/Max Resource:** អនុញ្ញាតឱ្យ Administrator កំណត់តម្លៃអប្បបរមា និងអតិបរមាសម្រាប់ Resource Requests និង Limits ដែល Pods អាចស្នើសុំបាន។ ឧទាហរណ៍ Pod មិនអាចស្នើសុំ CPU លើសពី 2 Cores ឬតិចជាង 100m បានទេ។
*   **បង្កើន Resource Utilization:** ដោយការកំណត់ Default Values និង Constraints វានឹងជួយឱ្យ Scheduler ធ្វើការសម្រេចចិត្តបានល្អប្រសើរ និងបង្កើនប្រសិទ្ធភាពនៃការប្រើប្រាស់ Resource ។

### អ្វីដែល Limit Ranges អាចកំណត់

Limit Ranges អាចអនុវត្តដែនកំណត់លើប្រភេទ Object បីយ៉ាង៖

1.  **Container:** កំណត់ដែនកំណត់សម្រាប់ Container នីមួយៗនៅក្នុង Pod ។
2.  **Pod:** កំណត់ដែនកំណត់សម្រាប់ Pod ទាំងមូល (ផលបូកនៃ Resources របស់ Containers ទាំងអស់ក្នុង Pod) ។
3.  **PersistentVolumeClaim:** កំណត់ដែនកំណត់ទំហំអប្បបរមា និងអតិបរមាសម្រាប់ PVCs ។

### ឧទាហរណ៍ Limit Range YAML

ខាងក្រោមនេះគឺជាឧទាហរណ៍នៃ Limit Range ដែលកំណត់ Resource Defaults និង Constraints សម្រាប់ Namespace `dev-team` ។

```yaml
%%writefile dev-team-limitrange.yaml
apiVersion: v1
kind: LimitRange # ប្រភេទ Resource គឺ LimitRange
metadata:
  name: cpu-mem-limit-range
  namespace: dev-team # អនុវត្តចំពោះ Namespace 'dev-team'
spec:
  limits:
  - default: # Resource Limits លំនាំដើមសម្រាប់ Containers
      cpu: 500m
      memory: 512Mi
    defaultRequest: # Resource Requests លំនាំដើមសម្រាប់ Containers
      cpu: 200m
      memory: 256Mi
    max: # Resource Limits អតិបរមាដែល Container អាចស្នើសុំ
      cpu: 1
      memory: 1Gi
    min: # Resource Requests អប្បបរមាដែល Container អាចស្នើសុំ
      cpu: 100m
      memory: 128Mi
    type: Container # អនុវត្តចំពោះ Container Object
```

**ការពន្យល់:**
*   `metadata.namespace: dev-team`: Limit Range នេះនឹងត្រូវបានអនុវត្តទៅលើ `dev-team` Namespace ។
*   `spec.limits.default`: កំណត់ Default Limit សម្រាប់ CPU និង Memory ទៅ 500m និង 512Mi រៀងៗខ្លួន។
*   `spec.limits.defaultRequest`: កំណត់ Default Request សម្រាប់ CPU និង Memory ទៅ 200m និង 256Mi រៀងៗខ្លួន។
*   `spec.limits.max`: កំណត់ Maximum Limit ដែល Container អាចមាន (1 CPU, 1 GiB Memory) ។
*   `spec.limits.min`: កំណត់ Minimum Request ដែល Container ត្រូវតែមាន (100m CPU, 128 MiB Memory) ។
*   `spec.limits.type: Container`: បញ្ជាក់ថាដែនកំណត់ទាំងនេះអនុវត្តចំពោះ Container Object ។

### Deploy និងផ្ទៀងផ្ទាត់

១. **បង្កើត Namespace `dev-team` (ប្រសិនបើមិនទាន់មាន):**
```yaml
!kubectl create namespace dev-team
```

២. **Deploy Limit Range:**
```yaml
!kubectl apply -f dev-team-limitrange.yaml
```

៣. **ពិនិត្យមើល Limit Range:**
```yaml
!kubectl get limitrange -n dev-team
```
### សាកល្បង Limit Ranges

ឥឡូវនេះយើងនឹងព្យាយាម Deploy Pod មួយទៅកាន់ `dev-team` Namespace ដោយ **មិនបញ្ជាក់** Resource Requests និង Limits ។ Limit Range នឹងដាក់ Default Values ឱ្យវាដោយស្វ័យប្រវត្តិ។

```yaml
%%writefile nginx-pod-no-resources.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-test-pod-no-resources
  namespace: dev-team
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
    ports:
    - containerPort: 80
```
១. **Deploy Pod:**
```yaml
!kubectl apply -f nginx-pod-no-resources.yaml
```

២. **ពិនិត្យព័ត៌មានលម្អិតរបស់ Pod:**
```yaml
!kubectl describe pod nginx-test-pod-no-resources -n dev-team
```
អ្នកគួរតែឃើញនៅក្នុងផ្នែក `Limits` និង `Requests` របស់ Container ថា Kubernetes បានដាក់ Default Values ឱ្យវាដោយស្វ័យប្រវត្តិ ដូចដែលបានកំណត់នៅក្នុង `cpu-mem-limit-range` ។

៣. **ព្យាយាម Deploy Pod ដែលស្នើសុំ Resource លើសពីដែនកំណត់ `max`:**

```yaml
%%writefile nginx-pod-exceed-limit.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-test-pod-exceed-limit
  namespace: dev-team
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
    resources:
      requests:
        memory: "2Gi" # លើសពី max memory request 1Gi
        cpu: "500m"
      limits:
        memory: "2Gi" # លើសពី max memory limit 1Gi
        cpu: "1"
    ports:
    - containerPort: 80
```

```yaml
!kubectl apply -f nginx-pod-exceed-limit.yaml
```

### សរុបមក

Limit Ranges គឺជាឧបករណ៍ដ៏ល្អមួយដើម្បីធ្វើឱ្យ Resource Management កាន់តែមានប្រសិទ្ធភាព និងអាចទស្សន៍ទាយបាននៅក្នុង Kubernetes Cluster ។ វាជួយធានាថា Pods ទាំងអស់មាន Resource Requests និង Limits ដែលសមរម្យ ហើយជួយអនុវត្ត Policy លើ Resource Consumption នៅកម្រិត Container និង Pod ។ ការប្រើប្រាស់ Limit Ranges រួមជាមួយ Resource Quotas ផ្តល់នូវការគ្រប់គ្រង Resource ដ៏ទូលំទូលាយនៅក្នុង Cluster របស់អ្នក។

```yaml
# លុប Pods និង Limit Range, Namespace
!kubectl delete -f nginx-test-pod-no-resources.yaml
!kubectl delete -f nginx-pod-exceed-limit.yaml
!kubectl delete -f dev-team-limitrange.yaml
!kubectl delete namespace dev-team
```

## ៦.៤ Taints និង Tolerations (ការគ្រប់គ្រងការដាក់ Pods នៅលើ Nodes)

នៅក្នុង Kubernetes, Scheduler ព្យាយាមដាក់ Pod ណាមួយនៅលើ Node ណាដែលសមស្របបំផុត។ ទោះជាយ៉ាងណាក៏ដោយ ជួនកាលយើងចង់ឱ្យ Nodes ជាក់លាក់មួយមានឥរិយាបទខុសពីធម្មតា។ ឧទាហរណ៍ យើងអាចចង់បម្រុងទុក Nodes មួយចំនួនសម្រាប់ Workloads ជាក់លាក់ ឬដើម្បីធានាថា Pods មិនត្រូវបានដាក់នៅលើ Nodes ដែលមាន Hardware ពិសេសដោយចៃដន្យ។

នេះគឺជាកន្លែងដែល **Taints** និង **Tolerations** ចូលមកដល់។

### ១. Taints

**Taint** ត្រូវបានអនុវត្តទៅលើ **Node** ។ វាជា Mark មួយដែលបង្ហាញថា Node នោះ **មិនគួរ** Schedule Pod ណាដែលមិន 'Tolerate' Taint នោះ។ និយាយឱ្យសាមញ្ញ Taint គឺជាវិធីមួយដើម្បី 'រុញច្រាន' Pods ចេញពី Node មួយ (repel Pods) ។

Taint នីមួយៗមាន `key`, `value` (optional), និង `effect` ។

#### Effects របស់ Taint:

*   **`NoSchedule`:** Pods នឹងមិនត្រូវបាន Schedule ទៅកាន់ Node នេះទេ លុះត្រាតែពួកវាមាន Toleration ដែលត្រូវគ្នា។ Pods ដែលកំពុងដំណើរការរួចហើយនៅលើ Node នេះនឹងនៅតែបន្តដំណើរការ។
*   **`PreferNoSchedule`:** Scheduler នឹងព្យាយាមជៀសវាងការដាក់ Pods នៅលើ Node នេះ ប៉ុន្តែវានឹងនៅតែដាក់ Pods នៅទីនោះ ប្រសិនបើគ្មានជម្រើសផ្សេងទៀតទេ។
*   **`NoExecute`:** នេះគឺជា Effect ខ្លាំងបំផុត។ Pods នឹងមិនត្រូវបាន Schedule ទៅកាន់ Node នេះទេ។ លើសពីនេះ Pods ដែលកំពុងដំណើរការរួចហើយនៅលើ Node នេះ ហើយមិនមាន Toleration ដែលត្រូវគ្នា **នឹងត្រូវបាន evicted (បណ្តេញចេញ)** ។ Pods ដែលមាន Toleration ដែលត្រូវគ្នា ប៉ុន្តែគ្មាន `tolerationSeconds` នឹងនៅតែបន្តដំណើរការ។

#### ការបន្ថែម Taint ទៅកាន់ Node

```yaml
# ពិនិត្យមើល Nodes របស់អ្នក (ឧទាហរណ៍ minikube Node)
!kubectl get nodes
```

```yaml
# បន្ថែម Taint ទៅកាន់ minikube Node
!kubectl taint nodes minikube special-hardware=true:NoSchedule
# ឧទាហរណ៍: Node នេះមាន Hardware ពិសេស ហើយ Pods ធម្មតាមិនគួរដំណើរការនៅទីនេះទេ
```

#### ការផ្ទៀងផ្ទាត់ Taint
```yaml
!kubectl describe node minikube | grep Taints
```

អ្នកគួរតែឃើញ `Taints: special-hardware=true:NoSchedule` ។

#### សាកល្បង Deploy Pod ដោយគ្មាន Toleration

ឥឡូវនេះយើងនឹងព្យាយាម Deploy Pod ធម្មតាទៅកាន់ Cluster ។ ដោយសារ Node `minikube` ត្រូវបាន Tainted ជាមួយ `NoSchedule` Pod នេះនឹងមិនត្រូវបាន Schedule ទៅកាន់ Node នោះទេ។
```yaml
%%writefile pod-no-toleration.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-no-toleration
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
```

```yaml
!kubectl apply -f pod-no-toleration.yaml
```

```yaml
!kubectl get pod pod-no-toleration
```

អ្នកនឹងឃើញ Pod ស្ថិតនៅក្នុង `Pending` Status ។ ប្រសិនបើអ្នកពិនិត្យមើល Events របស់វា អ្នកនឹងឃើញហេតុផល៖

!kubectl describe pod pod-no-toleration

អ្នកនឹងឃើញ Event មួយដែលបង្ហាញថា `0/1 nodes are available: 1 node(s) had untolerated taint {special-hardware: true}` ។

### ២. Tolerations

**Toleration** ត្រូវបានអនុវត្តទៅលើ **Pod** ។ វាអនុញ្ញាតឱ្យ Pod នោះ **អាចត្រូវបាន Schedule** ទៅកាន់ Node ដែលមាន Taint ដែលត្រូវគ្នា។ Toleration មិនធានាថា Pod នឹងត្រូវបាន Schedule ទៅកាន់ Node ដែលមាន Taint នោះទេ វាគ្រាន់តែអនុញ្ញាតឱ្យ Scheduler ពិចារណា Node នោះប៉ុណ្ណោះ។

#### របៀបកំណត់ Toleration នៅក្នុង PodSpec
```yaml
%%writefile pod-with-toleration.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-toleration
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
  tolerations:
  - key: "special-hardware"
    operator: "Equal"
    value: "true"
    effect: "NoSchedule"
```

**ការពន្យល់:**
*   `key`: ត្រូវតែត្រូវគ្នាជាមួយ Key របស់ Taint (`special-hardware`) ។
*   `operator`: `Equal` (ប្រសិនបើ Key និង Value ត្រូវគ្នា) ឬ `Exists` (ប្រសិនបើ Key ត្រូវគ្នា មិនខ្វល់ពី Value) ។
*   `value`: ត្រូវតែត្រូវគ្នាជាមួយ Value របស់ Taint (`true`) ។ (លុះត្រាតែ `operator: Exists`)
*   `effect`: ត្រូវតែត្រូវគ្នាជាមួយ Effect របស់ Taint (`NoSchedule`) ។

#### Deploy Pod ជាមួយ Toleration

```yaml
!kubectl apply -f pod-with-toleration.yaml
```

```yaml
!kubectl get pod pod-with-toleration
```

អ្នកគួរតែឃើញ Pod នេះស្ថិតនៅក្នុង `Running` Status ដោយសារវាមាន Toleration ដែលត្រូវគ្នាជាមួយ Taint របស់ Node `minikube` ។

### ឧទាហរណ៍ `NoExecute` Effect និង `tolerationSeconds`

ប្រសិនបើ Taint មាន Effect ជា `NoExecute` ហើយ Pod មាន Toleration ជាមួយ `tolerationSeconds` Pod នោះនឹងនៅតែដំណើរការលើ Node ដែលមាន Taint ប៉ុន្តែនឹងត្រូវបាន evicted បន្ទាប់ពីរយៈពេលដែលបានបញ្ជាក់។ នេះមានប្រយោជន៍សម្រាប់ Graceful Shutdowns ។

```yaml
# លុប Taint ចាស់
!kubectl taint nodes minikube special-hardware=true:NoSchedule-
```

```yaml
# បន្ថែម Taint ថ្មីជាមួយ NoExecute
!kubectl taint nodes minikube critical-workload=true:NoExecute
```

```yaml
%%writefile pod-with-toleration-seconds.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-toleration-seconds
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
  tolerations:
  - key: "critical-workload"
    operator: "Equal"
    value: "true"
    effect: "NoExecute"
    tolerationSeconds: 30 # Pod នឹងត្រូវបាន evicted បន្ទាប់ពី 30 វិនាទី
```

```yaml
!kubectl apply -f pod-with-toleration-seconds.yaml
```

ពិនិត្យមើល Status របស់ Pod នេះ។ វានឹងដំណើរការដំបូង ហើយបន្ទាប់មកនឹងត្រូវបាន evicted បន្ទាប់ពី 30 វិនាទី (ដោយសារ Taint `NoExecute` និង `tolerationSeconds`) ។

### ការលុប Taint ពី Node
```yaml
# លុប Taint ពី minikube Node
!kubectl taint nodes minikube critical-workload=true:NoExecute-
```

### សរុបមក

Taints និង Tolerations គឺជាឧបករណ៍ដ៏មានអានុភាពសម្រាប់ការគ្រប់គ្រងការដាក់ Pods នៅលើ Nodes ជាក់លាក់។

*   **Taints** ត្រូវបានប្រើដើម្បីសម្គាល់ Node មួយថាជា 'មិនសមរម្យ' សម្រាប់ការ Schedule Pods ធម្មតា។
*   **Tolerations** ត្រូវបានប្រើនៅក្នុង PodSpec ដើម្បីអនុញ្ញាតឱ្យ Pod មួយត្រូវបាន Schedule នៅលើ Node ដែលមាន Taint ដែលត្រូវគ្នា។

ការប្រើប្រាស់ Taints និង Tolerations អនុញ្ញាតឱ្យ Administrator បង្កើត Clusters ដែលមាន Nodes សម្រាប់គោលបំណងពិសេស ឬដើម្បីធានាថា Pods ដែលមានតម្រូវការជាក់លាក់ត្រូវបានដាក់នៅលើ Nodes ដែលសមស្របបំផុត។

## ៦.៥ Node Selectors និង Node Affinity (ការគ្រប់គ្រងការដាក់ Pods យ៉ាងជាក់លាក់)

នៅក្នុងជំពូកមុន យើងបានរៀនអំពី Taints និង Tolerations ដែលអនុញ្ញាតឱ្យយើង 'រុញច្រាន' Pods ចេញពី Nodes ជាក់លាក់។ ផ្ទុយទៅវិញ **Node Selectors** និង **Node Affinity** ផ្តល់នូវវិធីមួយដើម្បី 'ទាក់ទាញ' Pods ទៅកាន់ Nodes ដែលមានលក្ខណៈសម្បត្តិជាក់លាក់។ ពួកវាអនុញ្ញាតឱ្យអ្នកកំណត់យ៉ាងច្បាស់លាស់ថា Pod មួយគួរតែត្រូវបាន Schedule នៅលើ Node ណា ដោយផ្អែកលើ Labels របស់ Node នោះ។

### ហេតុអ្វីត្រូវប្រើ Node Selectors និង Node Affinity?

*   **ការដាក់ Pods នៅលើ Hardware ជាក់លាក់:** ឧទាហរណ៍ កម្មវិធីដែលត្រូវការ GPU អាចត្រូវបានដាក់នៅលើ Nodes ដែលមាន GPU ។
*   **ការបែងចែក Workloads:** បំបែក Workloads ផ្សេងៗគ្នាទៅកាន់ក្រុម Nodes ផ្សេងៗគ្នា (ឧទាហរណ៍ Backend Pods នៅលើ Nodes មួយក្រុម, Frontend Pods នៅលើ Nodes មួយក្រុមទៀត) ។
*   **ការបែងចែក Nodes តាមតំបន់:** ដាក់ Pods នៅលើ Nodes នៅក្នុង Availability Zone ជាក់លាក់មួយសម្រាប់ High Availability ។
*   **ការគ្រប់គ្រង License:** ដាក់កម្មវិធីដែលមាន License ថ្លៃនៅលើ Nodes តិចបំផុត។

### ១. Node Selectors

**Node Selector** គឺជាវិធីសាស្ត្រមូលដ្ឋានបំផុត និងសាមញ្ញបំផុតក្នុងការដាក់ Pods ទៅកាន់ Node មួយដែលមាន Label ជាក់លាក់។ អ្នកគ្រាន់តែបញ្ជាក់ Label Key-Value Pair នៅក្នុង PodSpec ហើយ Scheduler នឹងដាក់ Pod នោះនៅលើ Node ណាដែលមាន Label នោះ។

#### របៀបប្រើ Node Selectors

ដំបូង យើងត្រូវបន្ថែម Label ទៅកាន់ Node របស់យើង។ សម្រាប់ Minikube យើងនឹងបន្ថែម Label ថា `disk=ssd` ។
```yaml
# បន្ថែម Label ទៅកាន់ minikube Node
!kubectl label nodes minikube disk=ssd
```

#### ផ្ទៀងផ្ទាត់ Node Label

```yaml
# មើល Labels របស់ minikube Node
!kubectl get nodes --show-labels
```

អ្នកគួរតែឃើញ `disk=ssd` នៅក្នុងបញ្ជី Labels សម្រាប់ Node `minikube` ។

#### ឧទាហរណ៍ Pod YAML ជាមួយ Node Selector

```yaml
%%writefile pod-with-node-selector.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-node-selector
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
  nodeSelector:
    disk: ssd # Pod នេះនឹងត្រូវបាន Schedule នៅលើ Node ដែលមាន Label disk=ssd
```

#### Deploy និងផ្ទៀងផ្ទាត់
```yaml
# Deploy Pod
!kubectl apply -f pod-with-node-selector.yaml
```

```yaml
# ពិនិត្យមើល Status របស់ Pod
!kubectl get pod pod-with-node-selector
```

អ្នកគួរតែឃើញ Pod នេះស្ថិតនៅក្នុង `Running` Status ។

```yaml
# ពិនិត្យមើលព័ត៌មានលម្អិតរបស់ Pod ដើម្បីមើលថាវាត្រូវបានដាក់នៅលើ Node ណា
!kubectl describe pod pod-with-node-selector
```

នៅក្នុង Output អ្នកគួរតែឃើញ `Node: minikube` និង `Node-Selector: disk=ssd` ដែលបញ្ជាក់ថា Pod ត្រូវបានដាក់នៅលើ Node `minikube` ដែលមាន Label `disk=ssd` ។

### ២. Node Affinity

**Node Affinity** គឺជាលក្ខណៈពិសេសមួយកម្រិតខ្ពស់ជាង Node Selector ដែលផ្តល់នូវភាពបត់បែន (flexibility) កាន់តែច្រើនក្នុងការកំណត់ថា Pod មួយគួរត្រូវបាន Schedule នៅលើ Node ណា។ វាមិនត្រឹមតែអនុញ្ញាតឱ្យអ្នកជ្រើសរើស Nodes ដោយផ្អែកលើ Labels ប៉ុណ្ណោះទេ ប៉ុន្តែថែមទាំងអាចបញ្ជាក់ថា Pods គួរតែ **ត្រូវការ** (required) ឬ **ពេញចិត្ត** (preferred) Nodes ដែលមាន Labels ជាក់លាក់។

#### ប្រភេទ Node Affinity

មានពីរប្រភេទសំខាន់ៗនៃ Node Affinity:

*   **`requiredDuringSchedulingIgnoredDuringExecution`:** (តម្រូវនៅពេល Scheduling មិនអើពើនៅពេលដំណើរការ)
    *   Pod នឹងត្រូវបាន Schedule ទៅកាន់ Node ណាដែលបំពេញលក្ខខណ្ឌ Affinity ទាំងនេះ។ ប្រសិនបើគ្មាន Node ណាបំពេញលក្ខខណ្ឌទេ Pod នឹងមិនត្រូវបាន Schedule ទេ។
*   **`preferredDuringSchedulingIgnoredDuringExecution`:** (ពេញចិត្តនៅពេល Scheduling មិនអើពើនៅពេលដំណើរការ)
    *   Scheduler នឹងព្យាយាមដាក់ Pod ទៅកាន់ Node ណាដែលបំពេញលក្ខខណ្ឌ Affinity ទាំងនេះ ប៉ុន្តែប្រសិនបើរកមិនឃើញទេ Pod នៅតែអាចត្រូវបាន Schedule ទៅកាន់ Node ផ្សេងទៀត។ នេះជាប្រភេទ 'Soft' Affinity ។

#### ឧទាហរណ៍ Pod YAML ជាមួយ Node Affinity (`requiredDuringSchedulingIgnoredDuringExecution`)

```yaml
%%writefile pod-with-node-affinity.yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-node-affinity
spec:
  containers:
  - name: nginx-container
    image: nginx:latest
  affinity:
    nodeAffinity:
      requiredDuringSchedulingIgnoredDuringExecution:
        nodeSelectorTerms:
        - matchExpressions:
          - key: disk
            operator: In
            values:
            - ssd # Pod នេះនឹងត្រូវបាន Schedule នៅលើ Node ដែលមាន Label disk=ssd
            # Operator ផ្សេងទៀតអាចជា NotIn, Exists, DoesNotExist, Gt, Lt
```

#### Deploy និងផ្ទៀងផ្ទាត់

```yaml
# Deploy Pod
!kubectl apply -f pod-with-node-affinity.yaml
```

```yaml
# ពិនិត្យមើល Status របស់ Pod
!kubectl get pod pod-with-node-affinity
```

អ្នកគួរតែឃើញ Pod នេះស្ថិតនៅក្នុង `Running` Status ។

```yaml
# ពិនិត្យមើលព័ត៌មានលម្អិតរបស់ Pod ដើម្បីមើលថាវាត្រូវបានដាក់នៅលើ Node ណា
!kubectl describe pod pod-with-node-affinity
```
នៅក្នុង Output អ្នកគួរតែឃើញ `Node: minikube` និង `Node-Affinity` ដែលបញ្ជាក់ថា Pod ត្រូវបានដាក់នៅលើ Node `minikube` ដែលមាន Label `disk=ssd` ។

### សរុបមក

Node Selectors និង Node Affinity គឺជាឧបករណ៍ដ៏សំខាន់សម្រាប់ការគ្រប់គ្រងការដាក់ Pods នៅលើ Nodes ជាក់លាក់នៅក្នុង Kubernetes Cluster ។

*   **Node Selectors** គឺសាមញ្ញ ហើយប្រើសម្រាប់តម្រូវការដាក់ Pods ដែលតឹងរ៉ឹងដោយផ្អែកលើ Labels របស់ Node ។
*   **Node Affinity** ផ្តល់នូវភាពបត់បែនកាន់តែច្រើន ដោយមានលទ្ធភាព 'Required' ឬ 'Preferred' ការដាក់ Pods ដោយផ្អែកលើ Labels និង Operator ផ្សេងៗគ្នា។

ការប្រើប្រាស់ Node Selectors និង Node Affinity អនុញ្ញាតឱ្យ Administrator អាចរៀបចំ Nodes សម្រាប់គោលបំណងពិសេស និងធានាថា Pods ត្រូវបានដាក់នៅលើ Hardware ដែលសមស្របបំផុតសម្រាប់តម្រូវការរបស់ពួកវា។

```yaml
# Clean up
!kubectl delete -f pod-with-node-selector.yaml
!kubectl delete -f pod-with-node-affinity.yaml
!kubectl label nodes minikube disk-
```

```yaml
# Clean up
!kubectl delete -f pod-no-toleration.yaml
!kubectl delete -f pod-with-toleration.yaml
!kubectl delete -f pod-with-toleration-seconds.yaml
```