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

# ជំពូកទី ១៖ សេចក្តីផ្តើមអំពី Kubernetes

## ១.១ អ្វីទៅជា Container, Docker និងបញ្ហាដែលត្រូវដោះស្រាយ?

### Container

Container គឺជាបច្ចេកវិទ្យាដែលអនុញ្ញាតឱ្យអ្នកវេចខ្ចប់ (package) កម្មវិធីរបស់អ្នក រួមទាំង dependencies (ដូចជា libraries, binaries, configuration files) ទាំងអស់ចូលទៅក្នុងឯកតាស្វយ័តមួយ (isolated unit)។ វាដំណើរការដូចជាម៉ាស៊ីននិម្មិត (Virtual Machine) ប៉ុន្តែមានទម្ងន់ស្រាលជាង និងមានប្រសិទ្ធភាពជាង។

**លក្ខណៈសំខាន់ៗរបស់ Container:**

*   **ភាពចល័ត (Portability):** កម្មវិធីដែលវេចខ្ចប់ក្នុង Container អាចដំណើរការបានគ្រប់ទីកន្លែងដែលមាន Container Runtime (ដូចជា Docker) ដោយមិនគិតពីបរិស្ថានខាងក្រោម។ “Build once, run anywhere”។
*   **ភាពឯកោ (Isolation):** Container នីមួយៗត្រូវបានបំបែកចេញពីគ្នា និងពីប្រព័ន្ធប្រតិបត្តិការ Host ។ នេះមានន័យថាកម្មវិធីក្នុង Container មួយមិនអាចប៉ះពាល់ដល់កម្មវិធីផ្សេងទៀត ឬប្រព័ន្ធ Host បានទេ។
*   **ប្រសិទ្ធភាព (Efficiency):** Containers ចែករំលែក Kernel របស់ Host OS ដូច្នេះពួកវាស៊ីធនធានតិចជាង VMs ដែលនីមួយៗមាន OS ផ្ទាល់ខ្លួន។ នេះអនុញ្ញាតឱ្យអ្នកដំណើរការ Containers ជាច្រើននៅលើ Host តែមួយ។
*   **ភាពស៊ីគ្នា (Consistency):** ធានាថាកម្មវិធីរបស់អ្នកនឹងដំណើរការដូចគ្នាពី Development ទៅ Testing និង Production environment។

### Docker

Docker គឺជា Platform ដ៏ពេញនិយមបំផុតសម្រាប់បង្កើត, ដំណើរការ, និងគ្រប់គ្រង Containers។ វាបានក្លាយជាស្តង់ដារជាក់ស្តែង (de facto standard) នៅក្នុងឧស្សាហកម្មសម្រាប់បច្ចេកវិទ្យា Containerization។

**Docker ផ្តល់ជូននូវ:**

*   **Docker Engine:** ជា Daemon (Service) ដែលដំណើរការនៅលើ Host machine និងជាអ្នកទទួលខុសត្រូវក្នុងការកសាង, ដំណើរការ, និងគ្រប់គ្រង Containers។
*   **Docker Images:** គឺជា Template ដែលមានតែ Read-only ដែលប្រើសម្រាប់បង្កើត Containers។ Images មាន Code, runtime, system tools, system libraries និង settings ទាំងអស់ដែលកម្មវិធីត្រូវការ។
*   **Dockerfiles:** គឺជា Text file ដែលមានការណែនាំអំពីរបៀបបង្កើត Docker Image។
*   **Docker Hub:** ជា Cloud-based registry service សម្រាប់រក្សាទុក និងចែករំលែក Docker Images។

**ឧទាហរណ៍ Dockerfile សាមញ្ញ:**

```dockerfile
# ប្រើ Alpine Linux ជា Base Image ដែលមានទំហំតូច
FROM alpine:latest

# កំណត់ Working Directory នៅក្នុង Container
WORKDIR /app

# Copy កម្មវិធីទៅកាន់ Container
COPY . /app

# Command ដែលត្រូវដំណើរការនៅពេល Container ចាប់ផ្តើម
CMD ["echo", "Hello from Docker Container!"]
```

**CLI Commands របស់ Docker មួយចំនួន:**

*   `docker build -t my-app .`៖ កសាង Docker Image ពី Dockerfile នៅក្នុង Current directory ហើយដាក់ឈ្មោះថា `my-app`។
*   `docker run my-app`៖ ដំណើរការ Container ពី Image `my-app`។
*   `docker ps`៖ បង្ហាញ Containers ដែលកំពុងដំណើរការ។
*   `docker stop <container_id>`៖ បញ្ឈប់ Container។
*   `docker rm <container_id>`៖ លុប Container។

### បញ្ហាដែលត្រូវដោះស្រាយ

Containerization បានដោះស្រាយបញ្ហាជាច្រើនដែលទាក់ទងនឹងការ Deployment កម្មវិធី។ ទោះជាយ៉ាងណាក៏ដោយ នៅពេលដែលចំនួន Containers កើនឡើង រួមជាមួយការទាមទារនូវភាពស្មុគស្មាញនៃ Architecture (ដូចជា microservices) បញ្ហាថ្មីៗក៏កើតមានឡើង៖

1.  **ការគ្រប់គ្រង Containers ច្រើន (Managing Multiple Containers):** ប្រសិនបើអ្នកមាន Containers រាប់សិប ឬរាប់រយតើអ្នកគ្រប់គ្រងវាដោយរបៀបណា? តើធ្វើដូចម្តេចដើម្បីធានាថាពួកវាទាំងអស់កំពុងដំណើរការ?
2.  **ការដាក់ឱ្យដំណើរការ (Deployment):** តើអ្នកដាក់ឱ្យដំណើរការ Containers ទាំងនេះនៅលើ Servers ជាច្រើនដោយរបៀបណា? តើធ្វើដូចម្តេចដើម្បីធ្វើបច្ចុប្បន្នភាព (update) ពួកវាដោយមិនមាន Downtime?
3.  **ការពង្រីក (Scaling):** នៅពេល Demand កើនឡើង តើអ្នកបន្ថែម Containers ថ្មីដោយស្វ័យប្រវត្តិដោយរបៀបណា? ហើយនៅពេល Demand ធ្លាក់ចុះ តើអ្នកកាត់បន្ថយដោយរបៀបណា?
4.  **បណ្តាញ (Networking):** តើ Containers ផ្សេងៗគ្នាទំនាក់ទំនងគ្នាទៅវិញទៅមកដោយរបៀបណា? តើធ្វើដូចម្តេចដើម្បី expose កម្មវិធីទៅកាន់ពិភពខាងក្រៅ?
5.  **ការរក្សាទុកទិន្នន័យ (Storage):** Container គឺជា Stateless (ទិន្នន័យបាត់បង់នៅពេល Container ត្រូវបានលុប)។ តើធ្វើដូចម្តេចដើម្បីរក្សាទុកទិន្នន័យដែល Persistent (ជាប់លាប់)?
6.  **ភាពអាចរកបាន (High Availability):** ប្រសិនបើ Server ណាមួយបរាជ័យ តើ Containers របស់អ្នកនឹងផ្លាស់ប្តូរទៅ Server ផ្សេងទៀតដោយស្វ័យប្រវត្តិដោយរបៀបណា?
7.  **ការតាមដាន (Monitoring) និងការដោះស្រាយបញ្ហា (Troubleshooting):** តើធ្វើដូចម្តេចដើម្បីតាមដានស្ថានភាព Containers ទាំងអស់ និងដោះស្រាយបញ្ហានៅពេលវាកើតឡើង?

បញ្ហាទាំងនេះបាននាំឱ្យមានតម្រូវការសម្រាប់ **Container Orchestration Platforms** ដែលក្នុងនោះ **Kubernetes** គឺជាដំណោះស្រាយដ៏លេចធ្លោបំផុត។

## ១.២ អ្វីទៅជា Kubernetes (K8s)? ហេតុអ្វីត្រូវប្រើវា?

### អ្វីទៅជា Kubernetes (K8s)?

Kubernetes (K8s) គឺជាប្រព័ន្ធ Open-source សម្រាប់ធ្វើស្វ័យប្រវត្តិកម្ម (automating) ការដាក់ឱ្យដំណើរការ (deployment), ការធ្វើមាត្រដ្ឋាន (scaling), និងការគ្រប់គ្រង (management) កម្មវិធីដែលមាន Containerization។ ពាក្យ Kubernetes មានន័យថា 'អ្នកបើកបរ' (helmsman) ឬ 'អ្នកដឹកនាំ' (pilot) ជាភាសាក្រិក ដែលឆ្លុះបញ្ចាំងពីតួនាទីរបស់វាក្នុងការគ្រប់គ្រង Container Workloads។

Kubernetes ត្រូវបានបង្កើតឡើងដោយ Google ដោយផ្អែកលើបទពិសោធន៍ជាច្រើនឆ្នាំរបស់ពួកគេក្នុងការដំណើរការ Workloads រាប់ពាន់លានដោយប្រើប្រព័ន្ធខាងក្នុងរបស់ពួកគេឈ្មោះ Borg។ ក្រោយមក Google បាន Open-source Kubernetes ក្នុងឆ្នាំ 2014 ហើយឥឡូវនេះវាត្រូវបានថែរក្សាដោយ Cloud Native Computing Foundation (CNCF).

Kubernetes ដោះស្រាយបញ្ហាស្មុគស្មាញដែលយើងបានលើកឡើងនៅក្នុងផ្នែក ១.១ (Managing Multiple Containers, Deployment, Scaling, Networking, Storage, High Availability, Monitoring) ដោយផ្តល់ជូននូវ Platform ដ៏រឹងមាំមួយសម្រាប់ការគ្រប់គ្រង Containerized Applications នៅក្នុង Environments ផ្សេងៗគ្នា (On-premises, Hybrid, Public Cloud).

### ហេតុអ្វីត្រូវប្រើ Kubernetes?

ការប្រើប្រាស់ Kubernetes ផ្តល់អត្ថប្រយោជន៍ជាច្រើនសម្រាប់ Developers និង Operations Teams:

1.  **ស្វ័យប្រវត្តិកម្មនៃការដាក់ឱ្យដំណើរការ និងការគ្រប់គ្រង (Automated Deployments and Management):**
    *   **Automated Rollouts & Rollbacks:** Kubernetes អនុញ្ញាតឱ្យអ្នក Deploy ការផ្លាស់ប្តូរកូដ (new versions) ទៅកាន់កម្មវិធីរបស់អ្នកបន្តិចម្តងៗ (rolling updates) ដើម្បីធានាថាកម្មវិធីរបស់អ្នកនៅតែបន្តដំណើរការដោយគ្មានការរំខាន។ ប្រសិនបើមានបញ្ហា អ្នកអាច Rollback ទៅកាន់ Version មុនបានយ៉ាងងាយស្រួល។
    *   **Self-healing:** ប្រសិនបើ Container ណាមួយបរាជ័យ (Crash) ឬ Node ណាមួយ Offline, Kubernetes នឹងចាប់ផ្តើម Container ថ្មីដោយស្វ័យប្រវត្តិនៅលើ Nodes ផ្សេងទៀតដើម្បីធានាថា Service របស់អ្នកនៅតែដំណើរការ។

2.  **ការធ្វើមាត្រដ្ឋានដោយស្វ័យប្រវត្តិ (Automated Scaling):**
    *   **Horizontal Scaling:** អ្នកអាចកំណត់ឱ្យ Kubernetes បន្ថែមឬកាត់បន្ថយចំនួន Pods (ក្រុមនៃ Containers) ដោយស្វ័យប្រវត្តិដោយផ្អែកលើ Demand (ឧទាហរណ៍ CPU Utilization ឬ Custom Metrics)។ នេះធានាថាកម្មវិធីរបស់អ្នកមាន Resources គ្រប់គ្រាន់នៅពេលចាំបាច់ និងកាត់បន្ថយការចំណាយនៅពេល Demand ធ្លាក់ចុះ។

3.  **ការគ្រប់គ្រង Storage (Storage Orchestration):**
    *   Kubernetes អនុញ្ញាតឱ្យអ្នកភ្ជាប់ Persistent Storage (Local Storage, Cloud Storage, Network Storage) ទៅកាន់ Containers របស់អ្នក ធានាថាទិន្នន័យមិនបាត់បង់នៅពេល Container ត្រូវបានចាប់ផ្តើមឡើងវិញ ឬលុបចោល។

4.  **ការគ្រប់គ្រងបណ្តាញ និងការ Load Balance (Service Discovery & Load Balancing):**
    *   Kubernetes ផ្តល់ជូននូវយន្តការសម្រាប់ Service Discovery ដែលអនុញ្ញាតឱ្យ Containers ស្វែងរក និងទំនាក់ទំនងគ្នាទៅវិញទៅមកបានយ៉ាងងាយស្រួល។
    *   វាក៏មាន Built-in Load Balancer ដែលចែកចាយ Traffic ទៅកាន់ Pods នៃកម្មវិធីរបស់អ្នកដើម្បីធានានូវ High Availability និងប្រសិទ្ធភាព។

5.  **ការកំណត់រចនាសម្ព័ន្ធ និងការគ្រប់គ្រងទិន្នន័យសម្ងាត់ (Configuration Management & Secrets):**
    *   អ្នកអាចគ្រប់គ្រង Configuration របស់កម្មវិធីដោយឡែកពី Image របស់វាដោយប្រើ ConfigMaps។
    *   សម្រាប់ទិន្នន័យសម្ងាត់ (Passwords, API Keys) Kubernetes មានយន្តការ Secrets ដើម្បីរក្សាទុកពួកវាដោយសុវត្ថិភាព។

6.  **ភាពចល័តនៃ Infrastructure (Infrastructure Agnostic):**
    *   Kubernetes អាចដំណើរការបានលើ Cloud Providers ផ្សេងៗគ្នា (AWS, GCP, Azure) ក៏ដូចជា On-premises Servers ឬ Hybrid Environments។ នេះផ្តល់ឱ្យអ្នកនូវភាពបត់បែន និងជៀសវាងការជាប់គាំងជាមួយ Vendor ណាមួយ។

### សរុបមក

Kubernetes មិនមែនជាដំណោះស្រាយវេទមន្តដែលដោះស្រាយបញ្ហាទាំងអស់នោះទេ ហើយវាអាចមានភាពស្មុគស្មាញក្នុងការរៀន និងគ្រប់គ្រងដំបូង។ ទោះជាយ៉ាងណាក៏ដោយ អត្ថប្រយោជន៍ដែលវាផ្តល់ជូន ជាពិសេសសម្រាប់ Large-scale, Distributed Applications គឺមានតម្លៃខ្លាំងណាស់ក្នុងការវិនិយោគពេលវេលាដើម្បីរៀនវា។ វាបានក្លាយជាស្តង់ដារឧស្សាហកម្មសម្រាប់ការ Container Orchestration ហើយជាជំនាញដ៏សំខាន់មួយសម្រាប់វិស្វករ DevOps និង Cloud Engineer នាពេលបច្ចុប្បន្ន។

## ១.៣ ស្ថាបត្យកម្មរបស់ Kubernetes (Master Node និង Worker Node Components)

Kubernetes Cluster ត្រូវបានបង្កើតឡើងពី Nodes មួយចំនួន (machines) ដែលអាចជា Physical Servers ឬ Virtual Machines (VMs)។ Nodes ទាំងនេះត្រូវបានបែងចែកជាពីរប្រភេទសំខាន់ៗ៖ **Master Nodes (Control Plane)** និង **Worker Nodes**។

### ស្ថាបត្យកម្មរួម (Overall Architecture)

<img src="https://kubernetes.io/docs/images/kube-architecture.png" alt="Kubernetes Architecture" width="700"/>

### ១. Master Node (Control Plane)

Master Node គឺជាបេះដូងរបស់ Kubernetes Cluster។ វាទទួលខុសត្រូវក្នុងការគ្រប់គ្រង និងរៀបចំផែនការ (scheduling) Containers ទៅកាន់ Worker Nodes។ Master Node ត្រូវបានផ្សំឡើងដោយ Components សំខាន់ៗដូចខាងក្រោម:

1.  **Kube-apiserver:**
    *   **មុខងារ:** ជាចំណុចប្រទាក់ (interface) សំខាន់សម្រាប់ទំនាក់ទំនងជាមួយ Kubernetes Cluster។ រាល់សំណើ (requests) ទាំងអស់ទៅកាន់ Cluster ត្រូវឆ្លងកាត់ API Server នេះ។
    *   **ការពន្យល់:** វាធ្វើជា Gatekeeper ដោយផ្ទៀងផ្ទាត់ (authenticates) និងអនុញ្ញាត (authorizes) រាល់សំណើ។ APIs របស់ Kubernetes គឺជា HTTP REST API ដែលអាចត្រូវបានប្រើដោយ `kubectl` Command Line Tool, កម្មវិធីផ្សេងៗ ឬ User Interface។

2.  **Etcd:**
    *   **មុខងារ:** ជា Key-Value Store ដែលមានល្បឿនលឿន និងមានភាព Consistency ខ្ពស់ ដែលរក្សាទុកទិន្នន័យ Configuration ទាំងអស់របស់ Cluster។
    *   **ការពន្យល់:** Etcd គឺជា Database របស់ Kubernetes ដែលរក្សាទុក State ទាំងមូលរបស់ Cluster រួមមាន៖ Pods, Services, Deployments, ConfigMaps, Secrets, និងអ្វីៗទាំងអស់ដែលត្រូវបានកំណត់រចនាសម្ព័ន្ធនៅក្នុង Cluster។ វាមានសារៈសំខាន់ខ្លាំងណាស់ក្នុងការ Backup ទិន្នន័យ Etcd ។

3.  **Kube-scheduler:**
    *   **មុខងារ:** ទទួលខុសត្រូវក្នុងការសម្រេចចិត្តថា Pod ថ្មីនីមួយៗគួរដាក់ឱ្យដំណើរការនៅលើ Worker Node មួយណា។
    *   **ការពន្យល់:** Scheduler ពិនិត្យមើល Resource Requirements (CPU, Memory) របស់ Pods និង Resource Availability របស់ Worker Nodes ដើម្បីរក Node ល្អបំផុតសម្រាប់ Pod នីមួយៗ។ វាគិតគូរពី Constraints ផ្សេងៗដូចជា Co-location, Taints/Tolerations, Node Affinity ជាដើម។

4.  **Kube-controller-manager:**
    *   **មុខងារ:** ដំណើរការ Controller Processes ដែលតាមដាន State របស់ Cluster ហើយធ្វើការផ្លាស់ប្តូរដើម្បីនាំយក Cluster State ទៅកាន់ Desired State (State ដែលយើងចង់បាន)។
    *   **ការពន្យល់:** មាន Controllers ជាច្រើនដែលរួមបញ្ចូលគ្នានៅក្នុង Controller Manager ដូចជា:
        *   **Node Controller:** ទទួលខុសត្រូវក្នុងការត្រួតពិនិត្យ Nodes ។
        *   **Replication Controller:** ថែរក្សាចំនួន Pods ដែលបានកំណត់សម្រាប់ Deployment នីមួយៗ។
        *   **Endpoints Controller:** បង្កើត Endpoints Object ដែលភ្ជាប់ Services ទៅកាន់ Pods ។
        *   **Service Account & Token Controllers:** បង្កើត Default Accounts និង API Access Tokens សម្រាប់ Namespaces ថ្មី។

### ២. Worker Node (Data Plane)

Worker Node គឺជាកន្លែងដែល Workloads ពិតប្រាកដ (Containers) ត្រូវបានដំណើរការ។ Worker Node នីមួយៗមាន Components សំខាន់ៗដូចខាងក្រោម:

1.  **Kubelet:**
    *   **មុខងារ:** ជា Agent ដែលដំណើរការលើ Worker Node នីមួយៗ។ វាទទួលខុសត្រូវក្នុងការធានាថា Containers នៅក្នុង Pods កំពុងដំណើរការ និងមានសុខភាពល្អ។
    *   **ការពន្យល់:** Kubelet ទទួលបាន Pod Specifications (PodSpec) ពី API Server ហើយធានាថា Containers ដែលបានកំណត់ក្នុង PodSpec ត្រូវបានទាញយក (pulled), ដំណើរការ, និងត្រួតពិនិត្យសុខភាព (health-checked) ។

2.  **Kube-proxy:**
    *   **មុខងារ:** រក្សាទុក Rules របស់ Network នៅលើ Nodes ដែលអនុញ្ញាតឱ្យ Network Communication ទៅកាន់ Pods របស់អ្នកពីខាងក្នុង ឬខាងក្រៅ Cluster។
    *   **ការពន្យល់:** Kube-proxy គឺទទួលខុសត្រូវចំពោះ Service Abstraction របស់ Kubernetes។ វាធ្វើការ Load Balancing Traffic ឆ្លងកាត់ Pods ផ្សេងៗគ្នានៃ Service មួយ។

3.  **Container Runtime:**
    *   **មុខងារ:** ជា Software ដែលទទួលខុសត្រូវក្នុងការដំណើរការ Containers។
    *   **ការពន្យល់:** Kubernetes គាំទ្រ Container Runtimes ដូចជា Docker, containerd, និង CRI-O។ Container Runtime ទាញយក Images, ដំណើរការ Containers, និងគ្រប់គ្រង Lifecycle របស់វា។

### សរុបមក

ការយល់ដឹងពីស្ថាបត្យកម្មរបស់ Kubernetes គឺជាគន្លឹះក្នុងការគ្រប់គ្រង និងដោះស្រាយបញ្ហា (troubleshooting) Cluster របស់អ្នក។ Master Node (Control Plane) គ្រប់គ្រងរាល់សកម្មភាពទាំងអស់នៃ Cluster ខណៈដែល Worker Nodes (Data Plane) គឺជាកន្លែងដែលកម្មវិធីរបស់អ្នកត្រូវបានដំណើរការ។ ការបែងចែកតួនាទីនេះធ្វើឱ្យ Kubernetes មានភាពរឹងមាំ (resilient) និងមានលទ្ធភាពពង្រីក (scalable) ខ្ពស់។