# ជំពូកទី ៥៖ ការគ្រប់គ្រងទិន្នន័យ (Storage Management)

នៅក្នុងជំពូកមុនៗ យើងបានរៀនពីរបៀប Deploy និងគ្រប់គ្រងកម្មវិធីនៅក្នុង Kubernetes Cluster។ ទោះជាយ៉ាងណាក៏ដោយ Pods គឺជា Ephemeral (បណ្ដោះអាសន្ន) ដែលមានន័យថា នៅពេល Pod មួយត្រូវបានលុប ឬចាប់ផ្តើមឡើងវិញ ទិន្នន័យទាំងអស់ដែលត្រូវបានរក្សាទុកនៅក្នុង Container's Filesystem នឹងបាត់បង់។ នេះជាបញ្ហាសម្រាប់កម្មវិធីភាគច្រើនដែលត្រូវការរក្សាទុកទិន្នន័យ (Stateful Applications)។

ដើម្បីដោះស្រាយបញ្ហានេះ Kubernetes ផ្តល់ជូននូវយន្តការគ្រប់គ្រង Storage ដ៏រឹងមាំមួយគឺ **Volumes** និង **Persistent Volumes**។

## ៥.១ Volumes (ការរក្សាទុកទិន្នន័យបណ្តោះអាសន្ន)

### អ្វីទៅជា Volume?

**Volume** គឺជា Directory ដែលអាច Access បានដោយ Containers នៅក្នុង Pod មួយ។ វាមានលក្ខណៈពិសេសមួយគឺ Lifetime របស់វាត្រូវបានភ្ជាប់ទៅនឹង Lifetime របស់ Pod មិនមែន Lifetime របស់ Container នោះទេ។ នេះមានន័យថា ទិន្នន័យនៅក្នុង Volume នឹងនៅតែមាន ទោះបីជា Container នៅក្នុង Pod ត្រូវបាន Restart ឬ Replaced ក៏ដោយ។

Volume គឺចាំបាច់សម្រាប់៖

1.  **ការចែករំលែកទិន្នន័យ (Sharing Data):** Containers ច្រើននៅក្នុង Pod មួយអាចចែករំលែកទិន្នន័យរវាងគ្នាដោយ Mount Volume តែមួយ។
2.  **ការរក្សាទិន្នន័យនៅពេល Container Restart:** នៅពេល Container បរាជ័យ ហើយត្រូវបាន Restart ដោយ Kubelet ទិន្នន័យនៅក្នុង Volume នឹងនៅតែមាន។

**ចំណាំ:** Volumes ភាគច្រើន (លើកលែងតែប្រភេទមួយចំនួន) ត្រូវបានលុបចោលនៅពេល Pod ត្រូវបានលុប។ ដូច្នេះពួកវាត្រូវបានប្រើសម្រាប់ទិន្នន័យបណ្តោះអាសន្ន (Temporary Data) ឬទិន្នន័យដែលមិនចាំបាច់ Persistent ខ្លាំង។ សម្រាប់ទិន្នន័យ Persistent ពិតប្រាកដ យើងនឹងប្រើ **Persistent Volumes** នៅក្នុងផ្នែកបន្ទាប់។

### ប្រភេទនៃ Volumes

Kubernetes គាំទ្រប្រភេទ Volume ជាច្រើន ដែលនីមួយៗមានលក្ខណៈខុសៗគ្នា។ យើងនឹងលើកយកប្រភេទសំខាន់ៗមួយចំនួន:

1.  **`emptyDir`:**
    *   **ការពន្យល់:** គឺជា Volume ប្រភេទសាមញ្ញបំផុត។ វាត្រូវបានបង្កើតឡើងនៅពេល Pod ត្រូវបាន Assign ទៅ Node មួយ ហើយត្រូវបានលុបចោលនៅពេល Pod ត្រូវបានលុបចេញពី Node នោះ។ ឈ្មោះ `emptyDir` មកពីការពិតដែលថាវាចាប់ផ្តើមជា Directory ទទេ (empty directory)។
    *   **ការប្រើប្រាស់:** ល្អសម្រាប់ទិន្នន័យបណ្តោះអាសន្ន (Temporary Data), Caching Space, ឬសម្រាប់ Files ដែលត្រូវបាន Download នៅពេលចាប់ផ្តើម Pod ហើយលុបចោលនៅពេល Pod បញ្ចប់។

2.  **`hostPath`:**
    *   **ការពន្យល់:** Mount File ឬ Directory ពី Host Node Filesystem ទៅក្នុង Pod ។
    *   **ការប្រើប្រាស់:** សម្រាប់ Workloads ដែលត្រូវការ Access Files របស់ Host, សម្រាប់ Monitoring Agents, ឬសម្រាប់ Dev/Test Environment ។
    *   **ចំណាំ:** ការប្រើ `hostPath` មិនត្រូវបានណែនាំឱ្យប្រើនៅក្នុង Production Environment នោះទេ ព្រោះវាភ្ជាប់ Pod ទៅនឹង Node ជាក់លាក់មួយ ហើយអាចបណ្តាលឱ្យមានបញ្ហានៅពេល Scheduling, Security, និង Portability ។

3.  **`configMap` និង `secret`:**
    *   **ការពន្យល់:** Volumes ទាំងនេះត្រូវបានប្រើដើម្បី Mount ConfigMap ឬ Secret ជា Files ចូលទៅក្នុង Pod ។
    *   **ការប្រើប្រាស់:** សម្រាប់ Configuration Files ឬ Credentials ។

### របៀបប្រើប្រាស់ Volumes នៅក្នុង Pod

ដើម្បីប្រើ Volume អ្នកត្រូវធ្វើការកំណត់ពីរនៅក្នុង Pod Definition របស់អ្នក៖

1.  **កំណត់ Volume នៅក្នុង `spec.volumes`:** កំណត់ Volume (ឈ្មោះ, ប្រភេទ, និង Option ផ្សេងៗ) នៅកម្រិត Pod ។
2.  **Mount Volume នៅក្នុង `spec.containers.volumeMounts`:** បញ្ជាក់ថា Container មួយណាគួរតែ Mount Volume នោះ ហើយ Mount វាទៅកាន់ Path ណា។

#### ឧទាហរណ៍ទី ១: `emptyDir` Volume (ចែករំលែកទិន្នន័យរវាង Containers)

យើងនឹងបង្កើត Pod មួយដែលមាន Containers ពីរ៖ Container ទីមួយសរសេរ File ទៅក្នុង `emptyDir` ហើយ Container ទីពីរអាន File នោះ។

**ឧទាហរណ៍ Pod YAML (pod-with-empty-dir.yaml):**

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-empty-dir
spec:
  volumes: # កំណត់ Volume នៅកម្រិត Pod
  - name: shared-data # ឈ្មោះរបស់ Volume
    emptyDir: {} # បញ្ជាក់ថាជា emptyDir ប្រភេទ Volume
  containers:
  - name: writer-container
    image: alpine:latest
    command: ["/bin/sh", "-c"]
    args: ["echo 'Hello from writer' > /data/file.txt && sleep 60"]
    volumeMounts: # Mount Volume ចូលទៅក្នុង Container
    - name: shared-data # ឈ្មោះ Volume ដែលត្រូវ Mount
      mountPath: /data # Path នៅក្នុង Container ដែល Volume នឹងត្រូវបាន Mount
  - name: reader-container
    image: alpine:latest
    command: ["/bin/sh", "-c"]
    args: ["sleep 10 && cat /data/file.txt && sleep 60"]
    volumeMounts: # Mount Volume ចូលទៅក្នុង Container
    - name: shared-data # ឈ្មោះ Volume ដែលត្រូវ Mount
      mountPath: /data # Path នៅក្នុង Container ដែល Volume នឹងត្រូវបាន Mount
```

**ការពន្យល់:**

*   `volumes.name: shared-data`: យើងបានកំណត់ `shared-data` ជាឈ្មោះសម្រាប់ Volume របស់យើង។
*   `emptyDir: {}`: បញ្ជាក់ថា Volume នេះជាប្រភេទ `emptyDir` ។
*   `writer-container`: នឹងសរសេរ `Hello from writer` ទៅកាន់ `/data/file.txt` ។
*   `reader-container`: នឹងរង់ចាំ 10 វិនាទី បន្ទាប់មកអាន `/data/file.txt` ។
*   `volumeMounts.mountPath: /data`: Containers ទាំងពីរ Mount Volume ទៅកាន់ Path `/data` នៅក្នុង Filesystem របស់ពួកវា។

**របៀប Deploy និងផ្ទៀងផ្ទាត់:**

1.  **Deploy Pod:**
    ```bash
    kubectl apply -f pod-with-empty-dir.yaml
    ```

2.  **មើល Status របស់ Pod:**
    ```bash
    kubectl get pod pod-with-empty-dir
    ```
    រង់ចាំរហូតដល់ Pod ស្ថិតនៅក្នុង `Running` Status ។

3.  **មើល Logs របស់ `reader-container`:**
    ```bash
    kubectl logs pod-with-empty-dir -c reader-container
    ```
    អ្នកគួរតែឃើញ Output `Hello from writer` ដែលបង្ហាញថា `reader-container` អាចអាន File ដែលសរសេរដោយ `writer-container` ។

4.  **លុប Pod:**
    ```bash
    kubectl delete pod pod-with-empty-dir
    ```
    ទិន្នន័យនៅក្នុង `emptyDir` នឹងបាត់បង់នៅពេល Pod ត្រូវបានលុប។

#### ឧទាហរណ៍ទី ២: `hostPath` Volume (Mount ពី Host Node)

យើងនឹងបង្កើត Pod មួយដែល Mount Directory `/tmp/host-data` ពី Host Node ទៅកាន់ `/mnt/data` នៅក្នុង Container ។

**ឧទាហរណ៍ Pod YAML (pod-with-host-path.yaml):**

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-with-host-path
spec:
  volumes:
  - name: host-volume
    hostPath:
      path: /tmp/host-data # Path នៅលើ Host Node
      type: DirectoryOrCreate # ប្រសិនបើ Directory មិនមាន វានឹងបង្កើតវា
  containers:
  - name: my-container
    image: alpine:latest
    command: ["/bin/sh", "-c"]
    args: ["echo 'Data from hostPath' > /mnt/data/output.txt && tail -f /dev/null"]
    volumeMounts:
    - name: host-volume
      mountPath: /mnt/data
```

**របៀប Deploy និងផ្ទៀងផ្ទាត់:**

1.  **Deploy Pod:**
    ```bash
    kubectl apply -f pod-with-host-path.yaml
    ```

2.  **ចូលទៅកាន់ Host Node (Minikube):**
    ```bash
    minikube ssh # ប្រសិនបើអ្នកកំពុងប្រើ Minikube
    ```

3.  **នៅក្នុង Shell របស់ Minikube Node ពិនិត្យមាតិកានៃ File:**
    ```bash
    cat /tmp/host-data/output.txt
    ```
    អ្នកគួរតែឃើញ Output `Data from hostPath` ។

4.  **លុប Pod:**
    ```bash
    kubectl delete pod pod-with-host-path
    ```
    ទិន្នន័យនៅលើ Host Node (`/tmp/host-data/output.txt`) នឹងនៅតែមាន ទោះបីជា Pod ត្រូវបានលុបក៏ដោយ។

### សរុបមក

Volumes ផ្តល់នូវមធ្យោបាយមួយសម្រាប់ Container ក្នុងការរក្សាទុកទិន្នន័យដែលនៅតែមាននៅពេល Container Restart និងចែករំលែកទិន្នន័យរវាង Containers នៅក្នុង Pod តែមួយ។ ទោះបីជា `emptyDir` និង `hostPath` មានប្រយោជន៍សម្រាប់ Use Cases ជាក់លាក់ក៏ដោយ ពួកវាមិនមែនជាដំណោះស្រាយសម្រាប់ទិន្នន័យ Persistent នៅក្នុង Production Environment នោះទេ។ នៅក្នុងផ្នែកបន្ទាប់ យើងនឹងស្វែងយល់អំពី Persistent Volumes និង Persistent Volume Claims ដែលជាដំណោះស្រាយដ៏រឹងមាំសម្រាប់ទិន្នន័យ Persistent នៅក្នុង Kubernetes ។

## ៥.២ Persistent Volumes (PV) និង Persistent Volume Claims (PVC) (ការរក្សាទុកទិន្នន័យអចិន្ត្រៃយ៍)

នៅក្នុងផ្នែកមុន យើងបានដឹងថា Volumes ដូចជា `emptyDir` គឺ Ephemeral ហើយទិន្នន័យនឹងបាត់បង់នៅពេល Pod ត្រូវបានលុប។ សម្រាប់កម្មវិធី Stateful (ដែលត្រូវការរក្សាទុកទិន្នន័យ) ដូចជា Databases, Message Queues, ឬ Stateful Applications ផ្សេងៗ យើងត្រូវការយន្តការរក្សាទុកទិន្នន័យដែលនៅតែមាន ទោះបីជា Pod ត្រូវបានលុប ឬ Recreated ក៏ដោយ។

Kubernetes ដោះស្រាយបញ្ហានេះដោយប្រើប្រាស់ **Persistent Volumes (PVs)** និង **Persistent Volume Claims (PVCs)**។

### ១. Persistent Volume (PV)

**Persistent Volume (PV)** គឺជា Piece នៃ Storage នៅក្នុង Cluster ដែលត្រូវបាន Provision ដោយ Administrator ឬត្រូវបាន Provision ដោយ Dynamic (ដោយ Storage Class) ។ វាជា Resource នៅក្នុង Cluster ដូចជា Node មួយដែរ។ PV គឺជា Physical Storage ជាក់ស្តែងនៅក្នុង Infrastructure របស់អ្នក ដូចជា Google Persistent Disk, AWS EBS volume, Azure Disk, NFS Share, ឬ Local Disk នៅលើ Node មួយ។

**លក្ខណៈសំខាន់ៗរបស់ PV:**

*   **Independent of Pod Lifecycle:** PV ត្រូវបានបង្កើត និងមាន Lifecycle ឯករាជ្យពី Pod ។ ទិន្នន័យនៅក្នុង PV នឹងនៅតែមាន ទោះបីជា Pod ដែលប្រើវាត្រូវបានលុបក៏ដោយ។
*   **Resource in Cluster:** PV គឺជា Resource មួយដែលត្រូវ Provision មុននឹងប្រើប្រាស់។
*   **Storage Type Agnostic:** អាចប្រើជាមួយ Storage Provider ផ្សេងៗគ្នា (Cloud Providers, On-premises Storage) ។

**ឧទាហរណ៍ PV YAML (local-pv.yaml):**

ឧទាហរណ៍នេះបង្ហាញពី Local Persistent Volume ដែលចង្អុលទៅ Directory នៅលើ Host Node ។

```yaml
apiVersion: v1
kind: PersistentVolume # ប្រភេទ Resource គឺ PersistentVolume
metadata:
  name: local-pv # ឈ្មោះរបស់ PersistentVolume
spec:
  capacity:
    storage: 5Gi # ទំហំ Storage ដែលបាន Provision
  accessModes:
    - ReadWriteOnce # អនុញ្ញាតឱ្យ Node តែមួយប៉ុណ្ណោះអាច Mount វាជា ReadWrite
  persistentVolumeReclaimPolicy: Retain # រក្សាទិន្នន័យនៅពេល PVC ត្រូវបានលុប
  storageClassName: local-storage # ឈ្មោះ StorageClass (អាចប្តូរបាន)
  local:
    path: /mnt/data/local-storage # Path ពិតប្រាកដនៅលើ Host Node
  nodeAffinity:
    required:
      nodeSelectorTerms:
      - matchExpressions:
        - key: kubernetes.io/hostname
          operator: In
          values:
          - minikube # ត្រូវតែចង្អុលទៅឈ្មោះ Node ជាក់លាក់ (ក្នុងករណីនេះ Minikube Node)
```

**ការពន្យល់ពី YAML Fields:**

*   `capacity.storage`: កំណត់ទំហំ Storage របស់ PV (ឧទាហរណ៍ 5 Gigabytes) ។
*   `accessModes`: កំណត់របៀបដែល Volume អាចត្រូវបាន Mount ទៅកាន់ Pod ។
    *   `ReadWriteOnce (RWO)`: Volume អាចត្រូវបាន Mount ជា Read-Write ដោយ Node តែមួយ។
    *   `ReadOnlyMany (ROX)`: Volume អាចត្រូវបាន Mount ជា Read-Only ដោយ Nodes ជាច្រើន។
    *   `ReadWriteMany (RWX)`: Volume អាចត្រូវបាន Mount ជា Read-Write ដោយ Nodes ជាច្រើន។ (មិនគាំទ្រដោយ Storage Providers ទាំងអស់) ។
*   `persistentVolumeReclaimPolicy`: កំណត់អ្វីដែលត្រូវកើតឡើងចំពោះ Volume នៅពេល PVC ដែលប្រើវាត្រូវបានលុប។
    *   `Retain`: ទិន្នន័យ និង Resource នៅតែមាន។ Administrator ត្រូវលុបវាដោយដៃ។
    *   `Delete`: Volume និងទិន្នន័យរបស់វាត្រូវបានលុបដោយស្វ័យប្រវត្តិ។ (ប្រើជាមួយ Dynamic Provisioning) ។
    *   `Recycle`: ទិន្នន័យត្រូវបានលុប (wiped) ហើយ Volume អាចត្រូវបានប្រើឡើងវិញ។ (Deprecated សម្រាប់ PV types ភាគច្រើន) ។
*   `storageClassName`: ភ្ជាប់ PV ទៅ StorageClass ជាក់លាក់មួយ។
*   `local.path`: បញ្ជាក់ Local Path នៅលើ Node សម្រាប់ Local PV ។
*   `nodeAffinity`: សម្រាប់ Local PV វាចាំបាច់ត្រូវបញ្ជាក់ថា PV នេះមាននៅលើ Node មួយណា។

### ២. Persistent Volume Claim (PVC)

**Persistent Volume Claim (PVC)** គឺជា Request (សំណើ) សម្រាប់ Storage ដោយ Pod ។ វាជា Resource នៅក្នុង Namespace មួយ។ អ្នកប្រើប្រាស់ (ឬ Pod) គ្រាន់តែកំណត់លក្ខណៈសម្បត្តិរបស់ Storage ដែលពួកគេត្រូវការ (ទំហំ, Access Mode) ហើយ Kubernetes នឹងស្វែងរក PV ដែលសមស្របបំផុតសម្រាប់វា។

**លក្ខណៈសំខាន់ៗរបស់ PVC:**

*   **User's Request:** PVC គឺជាសំណើសម្រាប់ Storage ដោយអ្នកប្រើប្រាស់។
*   **Abstracts Storage Details:** Developers មិនចាំបាច់ដឹងពី Storage Provider ជាក់លាក់នោះទេ។
*   **Namespace-scoped:** PVC ស្ថិតនៅក្នុង Namespace ជាក់លាក់មួយ។

<img src="https://kubernetes.io/docs/images/docs/persistent-volumes.png" alt="Kubernetes PV and PVC Diagram" width="500"/>

**ឧទាហរណ៍ PVC YAML (nginx-pvc.yaml):**

```yaml
apiVersion: v1
kind: PersistentVolumeClaim # ប្រភេទ Resource គឺ PersistentVolumeClaim
metadata:
  name: nginx-data-pvc # ឈ្មោះរបស់ PersistentVolumeClaim
spec:
  accessModes:
    - ReadWriteOnce # សំណើសម្រាប់ Access Mode
  resources:
    requests:
      storage: 2Gi # សំណើសម្រាប់ទំហំ Storage
  storageClassName: local-storage # ត្រូវតែត្រូវគ្នាជាមួយ storageClassName របស់ PV
```

**ការពន្យល់ពី YAML Fields:**

*   `accessModes`: កំណត់ Access Mode ដែល PVC ត្រូវការ។ ត្រូវតែត្រូវគ្នាជាមួយ PV ។
*   `resources.requests.storage`: កំណត់ទំហំ Storage ដែល PVC ត្រូវការ (ឧទាហរណ៍ 2 Gigabytes) ។
*   `storageClassName`: ភ្ជាប់ PVC ទៅ StorageClass ជាក់លាក់មួយ។

### របៀបប្រើប្រាស់ PV និង PVC នៅក្នុង Pod

Pods ប្រើ PVC ដើម្បីស្នើសុំ Storage ។ ជំនួសឱ្យការចង្អុលទៅ Volume ជាក់លាក់មួយ Pod ចង្អុលទៅ PVC ។

**ឧទាហរណ៍ Pod YAML ដែលប្រើ PVC (nginx-pod-with-pvc.yaml):**

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod-with-pvc
spec:
  volumes:
    - name: persistent-storage
      persistentVolumeClaim:
        claimName: nginx-data-pvc # ចង្អុលទៅឈ្មោះ PVC ដែលបានបង្កើត
  containers:
    - name: nginx-container
      image: nginx:latest
      ports:
        - containerPort: 80
      volumeMounts:
        - name: persistent-storage
          mountPath: /usr/share/nginx/html # Mount Volume ទៅកាន់ Path សម្រាប់ Nginx Web Root
```

**ការពន្យល់:**

*   `volumes.persistentVolumeClaim.claimName`: បញ្ជាក់ឈ្មោះ PVC ដែល Pod ចង់ប្រើ។
*   `volumeMounts.mountPath`: កំណត់ Path នៅក្នុង Container ដែល Volume នឹងត្រូវបាន Mount ។

### ជំហាននៃការ Deploy និងផ្ទៀងផ្ទាត់ (នៅលើ Minikube)

#### ក. រៀបចំ Minikube Local Path

សម្រាប់ Local PV នៅក្នុង Minikube អ្នកត្រូវបង្កើត Directory នៅលើ Minikube VM ។

1.  **ចូលទៅកាន់ Minikube VM:**
    ```bash
    minikube ssh
    ```

2.  **បង្កើត Directory សម្រាប់ Local Storage:**
    ```bash
    sudo mkdir -p /mnt/data/local-storage
    sudo chmod 777 /mnt/data/local-storage # ផ្តល់សិទ្ធិ Access
    exit # ចេញពី Minikube VM
    ```

#### ខ. Deploy PV, PVC, និង Pod

1.  **រក្សាទុក YAML Files:** រក្សាទុក YAML ខាងលើទៅជា `local-pv.yaml`, `nginx-pvc.yaml`, និង `nginx-pod-with-pvc.yaml` រៀងៗខ្លួន។

2.  **Deploy PersistentVolume:**
    ```bash
    kubectl apply -f local-pv.yaml
    ```
    *   **ពិនិត្យ Status:**
        ```bash
        kubectl get pv
        ```
        អ្នកគួរតែឃើញ `local-pv` នៅក្នុង Status `Available` ។

3.  **Deploy PersistentVolumeClaim:**
    ```bash
    kubectl apply -f nginx-pvc.yaml
    ```
    *   **ពិនិត្យ Status:**
        ```bash
        kubectl get pvc
        ```
        អ្នកគួរតែឃើញ `nginx-data-pvc` នៅក្នុង Status `Bound` (ទៅនឹង `local-pv`) ។

    *   **ពិនិត្យ PV ម្តងទៀត:**
        ```bash
        kubectl get pv
        ```
        `local-pv` ឥឡូវនេះគួរតែស្ថិតនៅក្នុង Status `Bound` ។

4.  **Deploy Pod ដែលប្រើ PVC:**
    ```bash
    kubectl apply -f nginx-pod-with-pvc.yaml
    ```
    *   **ពិនិត្យ Status:**
        ```bash
        kubectl get pod nginx-pod-with-pvc
        ```
        រង់ចាំរហូតដល់ Pod ស្ថិតនៅក្នុង `Running` Status ។

#### គ. សាកល្បង Persistence

1.  **សរសេរ File ទៅកាន់ Persistent Volume:**
    ```bash
    kubectl exec -it nginx-pod-with-pvc -- bash
    ```
    *   នៅក្នុង Shell របស់ Container:
        ```bash
        echo "Hello from Kubernetes Persistent Storage!" > /usr/share/nginx/html/index.html
        exit
        ```

2.  **ផ្ទៀងផ្ទាត់ថាទិន្នន័យត្រូវបានរក្សាទុកនៅលើ Host Node (Minikube):**
    *   ចូលទៅកាន់ Minikube VM ម្តងទៀត:
        ```bash
        minikube ssh
        ```
    *   ពិនិត្យមាតិការបស់ File នៅលើ Host:
        ```bash
        cat /mnt/data/local-storage/index.html
        exit
        ```
        អ្នកគួរតែឃើញ `Hello from Kubernetes Persistent Storage!` ។ នេះបង្ហាញថាទិន្នន័យត្រូវបានសរសេរទៅកាន់ Volume ។

3.  **លុប Pod ចោល:**
    ```bash
    kubectl delete pod nginx-pod-with-pvc
    ```

4.  **Deploy Pod ថ្មីមួយម្តងទៀត (ជាមួយ PVC ដដែល):**
    ```bash
    kubectl apply -f nginx-pod-with-pvc.yaml
    ```

5.  **មើល Logs របស់ Pod ថ្មីដើម្បីផ្ទៀងផ្ទាត់ Persistence:**
    ```bash
    kubectl exec -it nginx-pod-with-pvc -- cat /usr/share/nginx/html/index.html
    ```
    អ្នកគួរតែឃើញ Output `Hello from Kubernetes Persistent Storage!` ដដែល។ នេះបញ្ជាក់ថាទិន្នន័យនៅតែមាន ទោះបីជា Pod ត្រូវបានលុប ហើយបង្កើតឡើងវិញក៏ដោយ។

### សរុបមក

Persistent Volumes (PVs) និង Persistent Volume Claims (PVCs) គឺជាគំនិតសំខាន់ៗដែលធ្វើឱ្យ Kubernetes អាចដំណើរការកម្មវិធី Stateful បានយ៉ាងមានប្រសិទ្ធភាព។ ពួកវាបំបែក Lifecycle របស់ Storage ចេញពី Lifecycle របស់ Pod ដែលអនុញ្ញាតឱ្យទិន្នន័យនៅតែមាន Persistent ទោះបីជា Pod ត្រូវបានលុប ឬ Recreated ក៏ដោយ។ ជាមួយ PVs និង PVCs អ្នកប្រើប្រាស់មិនចាំបាច់ដឹងពី Storage Provider ជាក់លាក់នោះទេ ដែលធ្វើឱ្យការគ្រប់គ្រង Storage កាន់តែងាយស្រួល និងបត់បែន។

## ៥.៣ StorageClass (Dynamic Provisioning)

នៅក្នុងផ្នែកមុន យើងបានរៀនអំពី Persistent Volumes (PVs) និង Persistent Volume Claims (PVCs)។ វិធីសាស្រ្តដែលយើងបានប្រើគឺ Static Provisioning ដែល Administrator ត្រូវបង្កើត PVs ជាមុន។ វិធីសាស្រ្តនេះអាចមានប្រសិទ្ធភាពសម្រាប់ Cluster តូចៗ ឬ Use Cases ជាក់លាក់ ប៉ុន្តែវាអាចជាបន្ទុកសម្រាប់ Cluster ធំៗដែលត្រូវការ Storage ច្រើនប្រភេទ និងទំហំខុសៗគ្នា។

ដើម្បីដោះស្រាយបញ្ហានេះ Kubernetes ផ្តល់ជូននូវ **StorageClass** ដែលអនុញ្ញាតឱ្យមាន **Dynamic Provisioning** នៃ Persistent Volumes ។

### អ្វីទៅជា StorageClass?

**StorageClass** គឺជា Resource នៅក្នុង Kubernetes ដែលផ្តល់នូវវិធីសាស្រ្តមួយក្នុងការកំណត់ **

“classes” នៃ Storage** ។ វាជា Abstraction សម្រាប់ Storage Provider ជាក់លាក់មួយ និងផ្តល់នូវ Parameters សម្រាប់ Provisioning Storage ។

**មុខងារសំខាន់ៗរបស់ StorageClass:**

*   **Dynamic Provisioning:** ជំនួសឱ្យការបង្កើត PVs ដោយដៃជាមុន StorageClass អនុញ្ញាតឱ្យ Kubernetes បង្កើត PV ថ្មីដោយស្វ័យប្រវត្តិនៅពេល PVC ស្នើសុំ Storage ។
*   **Abstraction Layer:** វាបំបែក Concept នៃ Storage ពីរបៀបដែល Storage ពិតប្រាកដត្រូវបាន Provision ។ អ្នក Developer គ្រាន់តែស្នើសុំ StorageClass ជាក់លាក់មួយដោយមិនចាំបាច់ដឹងពី Infrastructure ខាងក្រោមនោះទេ។
*   **Define Storage Types:** អ្នកអាចកំណត់ StorageClass ផ្សេងៗគ្នាសម្រាប់ Storage ប្រភេទផ្សេងគ្នា (ឧទាហរណ៍ Standard SSD, Premium SSD, High I/O, NFS) ជាមួយនឹងលក្ខណៈសម្បត្តិខុសៗគ្នា (Performance, Cost, Reclaim Policy) ។

### របៀបដែល Dynamic Provisioning ដំណើរការ

1.  **Administrator កំណត់ StorageClass:** Administrator បង្កើត StorageClass Object ដែលកំណត់ Provisioner (Storage Driver) និង Parameters (ឧទាហរណ៍ `type`, `zone`, `iops`)។
2.  **User បង្កើត PVC:** User (ឬ Deployment) បង្កើត PersistentVolumeClaim ដោយបញ្ជាក់ `storageClassName` ដែលខ្លួនចង់បាន និងទំហំ Storage ដែលត្រូវការ។
3.  **Kubernetes Provisions PV:** Kubernetes Controller (Kubernetes Master) រកឃើញ PVC ដែលស្នើសុំ StorageClass ។ Provisioner ដែលបានកំណត់នៅក្នុង StorageClass នឹងត្រូវបានហៅឱ្យបង្កើត PV ថ្មីនៅក្នុង Infrastructure ខាងក្រោម (ឧទាហរណ៍ បង្កើត Disk ថ្មីនៅក្នុង Cloud Provider) ។
4.  **PV ត្រូវបាន Bound ទៅ PVC:** PV ដែលត្រូវបាន Provision ថ្មីត្រូវបាន Bound ទៅនឹង PVC ដែលបានស្នើសុំវា។
5.  **Pod ប្រើ PVC:** Pod ប្រើ PVC ដូចធម្មតា ហើយទទួលបាន Storage ដែលត្រូវបាន Provision ដោយស្វ័យប្រវត្តិ។

### ឧទាហរណ៍ StorageClass YAML

នៅលើ Cloud Providers ភាគច្រើន StorageClass ត្រូវបានបង្កើតឡើងជា Default ។ ឧទាហរណ៍នៅលើ Google Kubernetes Engine (GKE) មាន `standard` និង `premium` StorageClass ។

សម្រាប់ Minikube, យើងអាចប្រើ `hostPath` Provisioner ដែលភ្ជាប់ជាមួយ `PersistentVolume provisioner` ខាងក្នុងរបស់ Minikube ។ Minikube មាន `standard` StorageClass លំនាំដើមដែលប្រើ `hostpath` ។

**១. មើល StorageClass ដែលមានស្រាប់:**

```bash
kubectl get storageclass
```

*   **ការពន្យល់:** នៅលើ Minikube អ្នកគួរតែឃើញ `standard` StorageClass ។

```
# ឧទាហរណ៍ Output លើ Minikube
NAME                 PROVISIONER                RECLAIMPOLICY   VOLUMEBINDINGMODE      ALLOWVOLUMEEXPANSION   AGE
standard (default)   k8s.io/minikube-hostpath   Delete          Immediate              false                  5d
```

*   `PROVISIONER`: បញ្ជាក់ Storage Driver ដែលត្រូវបានប្រើ (ឧទាហរណ៍ `k8s.io/minikube-hostpath` សម្រាប់ Minikube, `kubernetes.io/gce-pd` សម្រាប់ Google Persistent Disk) ។
*   `RECLAIMPOLICY`: កំណត់អ្វីដែលត្រូវកើតឡើងចំពោះ PV នៅពេល PVC ត្រូវបានលុប (ជាធម្មតា `Delete` សម្រាប់ការ Provisioning ដោយស្វ័យប្រវត្តិ) ។
*   `VOLUMEBINDINGMODE`: `Immediate` មានន័យថា PV ត្រូវបាន Bound ភ្លាមៗ។

**២. បង្កើត StorageClass ផ្ទាល់ខ្លួន (Minikube HostPath):**

ប្រសិនបើអ្នកចង់បង្កើត StorageClass ផ្ទាល់ខ្លួន អ្នកអាចធ្វើបាន។ សម្រាប់ Minikube យើងនឹងប្រើ `k8s.io/minikube-hostpath` ជា Provisioner ។

**ឧទាហរណ៍ StorageClass YAML (my-fast-storage.yaml):**

```yaml
apiVersion: storage.k8s.io/v1
kind: StorageClass # ប្រភេទ Resource គឺ StorageClass
metadata:
  name: my-fast-storage # ឈ្មោះរបស់ StorageClass
provisioner: k8s.io/minikube-hostpath # Provisioner សម្រាប់ Minikube hostpath
reclaimPolicy: Delete # PV នឹងត្រូវបានលុបនៅពេល PVC ត្រូវបានលុប
volumeBindingMode: Immediate # PV ត្រូវបាន Bound ភ្លាមៗ
parameters:
  type:

**ssd**

```yaml
apiVersion: storage.k8s.io/v1
kind: StorageClass
metadata:
  name: my-fast-storage
provisioner: k8s.io/minikube-hostpath # Provisioner សម្រាប់ Minikube hostpath
reclaimPolicy: Delete # PV នឹងត្រូវបានលុបនៅពេល PVC ត្រូវបានលុប
volumeBindingMode: Immediate # PV ត្រូវបាន Bound ភ្លាមៗ
# សម្រាប់ k8s.io/minikube-hostpath គឺមិនសូវមាន parameters ជាក់លាក់ទេ
# នៅក្នុង Cloud Providers អាចមាន parameters ដូចជា type, zone, iops ជាដើម។
```

**៣. Deploy StorageClass ផ្ទាល់ខ្លួន:**

រក្សាទុក YAML ខាងលើទៅក្នុង File មួយឈ្មោះ `my-fast-storage.yaml` រួច Deploy:

```bash
kubectl apply -f my-fast-storage.yaml
```

**៤. ផ្ទៀងផ្ទាត់ StorageClass:**

```bash
kubectl get storageclass
```

អ្នកគួរតែឃើញ `my-fast-storage` នៅក្នុងបញ្ជី។

### របៀបប្រើប្រាស់ StorageClass សម្រProvisioningProProvisioningvisioning
០
ឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimmឥឡូវនេះយើងនឹងបង្កPersisឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimmឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimlumeClaimtentVolumeClaimimlumeCឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimmឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimlumeClaimtentVolumeClaimimlumeCtentVolumeClaimlumeClaimtentVolumeClaimlumeClaimtentVolumeClaimimlumeClaimtentVolumeClaimឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimmឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimlumeClaimtentVolumeClaimmឥឡូវនេះយើងនឹងបង្កPersistentVolumeClaimlumeClaimtentVolumeClaimlumeClaimtentVolumeClaim (PVC) ដែលប្រើ `my-fast-storage` StorageClass ។ Kubernetes នឹងប្រើ StorageClass នេះដើម្បី Provision PV ថ្មីដោយស្វ័យប្រវត្តិ។

**ឧទាហរណ៍ PVC YAML (my-dynamic-pvc.yaml):**

```yaml
apiVersion: v1
kind: PersistentVolumeClaim # ប្រភេទ Resource គឺ PersistentVolumeClaim
metadata:
  name: my-dynamic-pvc # ឈ្មោះរបស់ PersistentVolumeClaim
spec:
  accessModes:
    - ReadWriteOnce # សំណើសម្រាប់ Access Mode
  resources:
    requests:
      storage: 1Gi # សំណើសម្រាប់ទំហំ Storage
  storageClassName: my-fast-storage # បញ្ជាក់ឈ្មោះ StorageClass ដែលយើងចង់ប្រើ
```

**ការពន្យល់:**

*   `storageClassName: my-fast-storage`: PVC នេះស្នើសុំ Storage ពី `my-fast-storage` StorageClass ។ នៅពេល PVC នេះត្រូវបានបង្កើត Kubernetes នឹងហៅ `k8s.io/minikube-hostpath` Provisioner ដែលបានកំណត់នៅក្នុង `my-fast-storage` StorageClass ដើម្បីបង្កើត PV ថ្មីដែលមានទំហំ 1Gi ។

### ជំហាននៃការ Deploy និងផ្ទៀងផ្ទាត់ Dynamic Provisioning

1.  **Deploy PersistentVolumeClaim (PVC):**
    រក្សាទុក YAML ខាងលើទៅជា `my-dynamic-pvc.yaml` រួច Deploy:
    ```bash
kubectl apply -f my-dynamic-pvc.yaml
    ```

2.  **ពិនិត្យ Status របស់ PVC:**
    ```bash
kubectl get pvc
    ```
    អ្នកគួរតែឃើញ `my-dynamic-pvc` នៅក្នុង Status `Pending` រយៈពេលខ្លី ហើយបន្ទាប់មកប្តូរទៅ `Bound` ។

    ```
# ឧទាហរណ៍ Output
NAME             STATUS   VOLUME                                     CAPACITY   ACCESS MODES   STORAGECLASS      AGE
my-dynamic-pvc   Bound    pvc-f7a6f2b4-5c9e-4e0d-b8d2-1c2c2f6d0f7d   1Gi        RWO            my-fast-storage   10s
    ```

3.  **ពិនិត្យ PV ដែលត្រូវបាន Provision ដោយស្វ័យប្រវត្តិ:**
    ```bash
kubectl get pv
    ```
    អ្នកគួរតែឃើញ PV ថ្មីមួយត្រូវបានបង្កើតដោយស្វ័យប្រវត្តិ ហើយវាត្រូវបាន Bound ទៅ `my-dynamic-pvc` ។ ឈ្មោះរបស់ PV នឹងជា UUID ដូចក្នុងឧទាហរណ៍។

    ```
# ឧទាហរណ៍ Output
NAME                                       CAPACITY   ACCESS MODES   RECLAIM POLICY   STATUS   CLAIM                  STORAGECLASS      REASON   AGE
pvc-f7a6f2b4-5c9e-4e0d-b8d2-1c2c2f6d0f7d   1Gi        RWO            Delete           Bound    default/my-dynamic-pvc   my-fast-storage   15s
    ```

### ប្រើ Pod ជាមួយ PVC ដែលបាន Provision ដោយ Dynamic

ឥឡូវនេះយើងនឹងបង្កើត Pod មួយដែលប្រើ `my-dynamic-pvc` ។

**ឧទាហរណ៍ Pod YAML (nginx-pod-with-dynamic-pvc.yaml):**

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod-dynamic
spec:
  volumes:
    - name: dynamic-storage
      persistentVolumeClaim:
        claimName: my-dynamic-pvc # ចង្អុលទៅឈ្មោះ PVC ដែលបានបង្កើត
  containers:
    - name: nginx-container
      image: nginx:latest
      ports:
        - containerPort: 80
      volumeMounts:
        - name: dynamic-storage
          mountPath: /usr/share/nginx/html # Mount Volume ទៅកាន់ Path សម្រាប់ Nginx Web Root
```

1.  **Deploy Pod:**
    ```bash
kubectl apply -f nginx-pod-with-dynamic-pvc.yaml
    ```

2.  **ផ្ទៀងផ្ទាត់ Pod:**
    ```bash
kubectl get pod nginx-pod-dynamic
    ```

3.  **សាកល្បង Persistence (ដូចដែលយើងបានធ្វើនៅក្នុងផ្នែក ៥.២):**
    ```bash
kubectl exec -it nginx-pod-dynamic -- bash
# នៅក្នុង Shell របស់ Container:
echo "Hello from Dynamic Provisioned Storage!" > /usr/share/nginx/html/index.html
exit
    ```

4.  **លុប Pod:**
    ```bash
kubectl delete pod nginx-pod-dynamic
    ```

5.  **Deploy Pod ថ្មីម្តងទៀត ហើយពិនិត្យមាតិកា:**
    ```bash
kubectl apply -f nginx-pod-with-dynamic-pvc.yaml
kubectl exec -it nginx-pod-dynamic -- cat /usr/share/nginx/html/index.html
    ```
    អ្នកគួរតែឃើញ `Hello from Dynamic Provisioned Storage!` ដដែល។

### សរុបមក

**StorageClass** គឺជា Resource ដ៏មានឥទ្ធិពលដែលអនុញ្ញាតឱ្យ Kubernetes ធ្វើ **Dynamic Provisioning** នៃ Persistent Volumes ។ វាជួយសម្រួលដល់ការគ្រប់គ្រង Storage នៅក្នុង Cluster យ៉ាងខ្លាំង ដោយអនុញ្ញាតឱ្យ Developers ស្នើសុំ Storage តាមតម្រូវការដោយមិនចាំបាច់មានអន្តរាគមន៍ពី Administrator ក្នុងការ Provision PV នោះទេ។ នេះធ្វើឱ្យការគ្រប់គ្រង Storage កាន់តែមានភាពបត់បែន, scalable, និង Automation ។ នៅពេលដែល PVC ត្រូវបានលុប PV ដែលត្រូវបាន Provision ដោយ Dynamic ក៏នឹងត្រូវបានលុបដោយស្វ័យប្រវត្តិផងដែរ (ប្រសិនបើ `reclaimPolicy` របស់ StorageClass គឺ `Delete`) ។
