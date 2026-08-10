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


# ជំពូកទី ២៖ ការរៀបចំប្រព័ន្ធ (Setup & Installation)

## ២.១ ការដំឡើង Minikube ដើម្បីរៀននៅលើកុំព្យូទ័រផ្ទាល់ខ្លួន

ដើម្បីចាប់ផ្តើមរៀន និងអនុវត្តជាមួយ Kubernetes នៅលើកុំព្យូទ័រផ្ទាល់ខ្លួនរបស់អ្នក វិធីងាយស្រួលបំផុតគឺប្រើ **Minikube**។ Minikube គឺជាឧបករណ៍មួយដែលអនុញ្ញាតឱ្យអ្នកដំណើរការ Single-Node Kubernetes Cluster នៅលើ Local Machine របស់អ្នក។ វាល្អឥតខ្ចោះសម្រាប់ការអភិវឌ្ឍន៍ (development), ការធ្វើតេស្ត (testing), និងការសិក្សា (learning)។

### តម្រូវការជាមុន (Prerequisites)

មុនពេលដំឡើង Minikube អ្នកត្រូវមាន:

1.  **Virtualization Software:** Minikube ត្រូវការ Hypervisor (កម្មវិធីសម្រាប់បង្កើត Virtual Machines)។ ឧទាហរណ៍:
    *   **Windows:** Hyper-V (សម្រាប់ Windows 10 Pro/Enterprise) ឬ VirtualBox.
    *   **macOS:** HyperKit (Built-in) ឬ VirtualBox, VMWare Fusion.
    *   **Linux:** KVM/libvirt ឬ VirtualBox.
2.  **RAM:** យ៉ាងហោចណាស់ 2GB (ល្អបំផុត 4GB).
3.  **CPU:** យ៉ាងហោចណាស់ 2 Cores.
4.  **Disk Space:** យ៉ាងហោចណាស់ 20GB.

### ជំហាននៃការដំឡើង Minikube

ការដំឡើង Minikube មានពីរជំហានសំខាន់ៗ៖ ដំឡើង `kubectl` (Kubernetes Command-Line Tool) និងដំឡើង `minikube` ខ្លួនឯង។

#### ជំហានទី ១: ដំឡើង kubectl

`kubectl` គឺជា Command-Line Tool ផ្លូវការរបស់ Kubernetes ដែលអនុញ្ញាតឱ្យអ្នកដំណើរការ Commands ប្រឆាំងនឹង Kubernetes Clusters។

**សម្រាប់ Windows:**

1.  បើក PowerShell ជា Administrator.
2.  ទាញយក `kubectl` executable:
    ```powershell
    curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/windows/amd64/kubectl.exe"
    ```
3.  បន្ថែម `kubectl.exe` ទៅក្នុង System PATH ឬផ្លាស់ទីវាទៅ Directory ដែលមានស្រាប់ក្នុង PATH (ឧទាហរណ៍ `C:\Windows` ឬ `C:\Windows\System32`)។
4.  ផ្ទៀងផ្ទាត់ការដំឡើង:
    ```powershell
    kubectl version --client
    ```

**សម្រាប់ macOS (ប្រើ Homebrew):**

```bash
brew install kubectl
```
ផ្ទៀងផ្ទាត់ការដំឡើង:

```bash
kubectl version --client
```

**សម្រាប់ Linux (ប្រើ apt):**

```bash
sudo apt update
sudo apt install -y apt-transport-https ca-certificates curl
curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.28/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
sudo chmod 644 /etc/apt/keyrings/kubernetes-apt-keyring.gpg # allow unauthenticated access
echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.28/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list
sudo apt update
sudo apt install -y kubectl
```

ផ្ទៀងផ្ទាត់ការដំឡើង:

```bash
kubectl version --client
```

#### ជំហានទី ២: ដំឡើង Minikube

**សម្រាប់ Windows:**

1.  ទាញយក `minikube.exe` ពី [Minikube releases page](https://github.com/kubernetes/minikube/releases).
2.  ប្តូរឈ្មោះ File ទៅ `minikube.exe` ហើយផ្លាស់ទីវាទៅ `C:\minikube` (ឬ Directory ណាមួយដែលអ្នកចង់បាន)។
3.  បន្ថែម `C:\minikube` ទៅក្នុង System PATH Environment Variable.
4.  បើក Command Prompt (cmd) ឬ PowerShell ជា Administrator.
5.  ចាប់ផ្តើម Minikube Cluster (ត្រូវប្រាកដថា Hypervisor របស់អ្នកកំពុងដំណើរការ)។ ឧទាហរណ៍ ប្រើ VirtualBox:
    ```bash
    minikube start --driver=virtualbox
    ```
    ឬ Hyper-V (ប្រសិនបើមាន):
    ```bash
    minikube start --driver=hyperv
    ```

**សម្រាប់ macOS (ប្រើ Homebrew):**

```bash
brew install minikube
minikube start # វានឹងជ្រើសរើស Driver ល្អបំផុតដោយស្វ័យប្រវត្តិ (ឧទាហរណ៍ HyperKit)
```

**សម្រាប់ Linux (ទាញយក Binary):**

```bash
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube
minikube start
```

### ការផ្ទៀងផ្ទាត់ការដំឡើង Minikube

នៅពេល Minikube Cluster ចាប់ផ្តើមដំណើរការ អ្នកអាចផ្ទៀងផ្ទាត់វាដោយប្រើ Commands ទាំងនេះ:

1.  **ពិនិត្យស្ថានភាព Minikube:**
    ```bash
    minikube status
    ```
    អ្នកគួរតែឃើញ Output ដែលបង្ហាញថា `minikube` និង `kubelet` កំពុងដំណើរការ។

2.  **ពិនិត្យ Nodes នៅក្នុង Cluster (ដោយប្រើ kubectl):**
    ```bash
    kubectl get nodes
    ```
    អ្នកគួរតែឃើញ Node មួយដែលមានឈ្មោះ `minikube` និង Status `Ready`។

### Commands សំខាន់ៗរបស់ Minikube

*   `minikube start`: ចាប់ផ្តើម Minikube Cluster.
*   `minikube stop`: បញ្ឈប់ Minikube Cluster (Preserves its state).
*   `minikube delete`: លុប Minikube Cluster ទាំងស្រុង.
*   `minikube ip`: បង្ហាញ IP Address របស់ Minikube Cluster.
*   `minikube dashboard`: បើក Kubernetes Dashboard UI នៅក្នុង Browser.

ឥឡូវនេះអ្នកបានដំឡើង Minikube រួចរាល់ហើយ អ្នកមាន Kubernetes Cluster តូចមួយដែលអាចដំណើរការបាននៅលើកុំព្យូទ័ររបស់អ្នកសម្រាប់គោលបំណងសិក្សា និងអភិវឌ្ឍន៍។

## ២.២ ការប្រើប្រាស់ kubectl (Kubernetes Command Line Tool) ជាមូលដ្ឋាន

`kubectl` គឺជា Command-Line Tool ដ៏សំខាន់សម្រាប់គ្រប់គ្រង Kubernetes Cluster របស់អ្នក។ វាអនុញ្ញាតឱ្យអ្នកដំណើរការ Commands ប្រឆាំងនឹង Kubernetes Cluster, Deploy កម្មវិធី, ត្រួតពិនិត្យ និងគ្រប់គ្រង Cluster Resources, និងមើល Logs ។

### Syntax មូលដ្ឋាន

Syntax ទូទៅរបស់ `kubectl` command គឺ:

```bash
kubectl [command] [type] [name] [flags]
```

*   `command`: ជាប្រតិបត្តិការដែលអ្នកចង់ធ្វើ (ឧទាហរណ៍ `get`, `create`, `delete`, `apply`, `describe`)។
*   `type`: ជាប្រភេទ Resource របស់ Kubernetes (ឧទាហរណ៍ `pod`, `deployment`, `service`, `node`)។ អ្នកអាចប្រើទម្រង់ពហុវចនៈ (plural) ឬអក្សរកាត់ (short name) ក៏បាន (ឧទាហរណ៍ `pods` ឬ `po`)។
*   `name`: ឈ្មោះរបស់ Resource។ ប្រសិនបើអ្នកមិនបញ្ជាក់ឈ្មោះទេ Command នឹងដំណើរការលើ Resources ទាំងអស់នៃប្រភេទនោះ។
*   `flags`: ជា Optional Flags (ឧទាហរណ៍ `-n` សម្រាប់ Namespace, `-o` សម្រាប់ Output format)។

### Commands ទូទៅដែលត្រូវប្រើ

ខាងក្រោមនេះគឺជា Commands របស់ `kubectl` ដែលត្រូវបានប្រើប្រាស់ជាទូទៅបំផុត:

#### ១. `kubectl get` – បង្ហាញ Resources

ប្រើដើម្បីទាញយក និងបង្ហាញព័ត៌មានអំពី Resources របស់ Kubernetes ។

*   **មើល Nodes ទាំងអស់:**
    ```bash
    kubectl get nodes
    ```
    *   **ការពន្យល់:** បង្ហាញបញ្ជី Nodes នៅក្នុង Cluster រួមជាមួយ Status, Roles, Ages, និង Version។

*   **មើល Pods ទាំងអស់នៅក្នុង Namespace បច្ចុប្បន្ន:**
    ```bash
    kubectl get pods
    ```
    *   **ការពន្យល់:** បង្ហាញបញ្ជី Pods ដែលកំពុងដំណើរការ (ឬនៅក្នុង Status ផ្សេងទៀត) នៅក្នុង Namespace ដែលអ្នកកំពុងប្រើប្រាស់បច្ចុប្បន្ន។

*   **មើល Deployments ទាំងអស់:**
    ```bash
    kubectl get deployments
    ```
    *   **ការពន្យល់:** បង្ហាញបញ្ជី Deployments ។

*   **មើល Services ទាំងអស់:**
    ```bash
    kubectl get services
    ```
    *   **ការពន្យល់:** បង្ហាញបញ្ជី Services ។

*   **មើល Resource ជាក់លាក់មួយដោយឈ្មោះ (ឧទាហរណ៍ Pod ឈ្មោះ `my-pod`):**
    ```bash
    kubectl get pod my-pod
    ```

*   **មើល Resources ក្នុង Namespace ជាក់លាក់ (ឧទាហរណ៍ Pods ក្នុង `kube-system`):**
    ```bash
    kubectl get pods -n kube-system
    ```

*   **បង្ហាញព័ត៌មានលម្អិតបន្ថែម (Wide Output):**
    ```bash
    kubectl get pods -o wide
    ```
    *   **ការពន្យល់:** បន្ថែម Column ព័ត៌មានដូចជា IP Addresses របស់ Pods និង Node ដែល Pod កំពុងដំណើរការ។

*   **បង្ហាញ Output ជា YAML ឬ JSON:**
    ```bash
    kubectl get pod my-pod -o yaml
    kubectl get pod my-pod -o json
    ```
    *   **ការពន្យល់:** មានប្រយោជន៍ខ្លាំងណាស់សម្រាប់ការ Debugging ឬការយល់ដឹងពី Configuration លម្អិតរបស់ Resource ។

#### ២. `kubectl describe` – បង្ហាញព័ត៌មានលម្អិតអំពី Resource

ប្រើដើម្បីបង្ហាញព័ត៌មានលម្អិតអំពី Resource ជាក់លាក់មួយ រួមទាំង Event របស់វា។

*   **បង្ហាញព័ត៌មានលម្អិតអំពី Pod មួយ:**
    ```bash
    kubectl describe pod my-pod
    ```
    *   **ការពន្យល់:** នឹងបង្ហាញព័ត៌មានដូចជា Labels, Annotations, Status, Events, Containers, Volumes, និង Network Configuration។ Events គឺមានសារៈសំខាន់ខ្លាំងណាស់សម្រាប់ការ Debugging បញ្ហា។

#### ៣. `kubectl logs` – មើល Logs របស់ Container

ប្រើដើម្បីមើល Logs ពី Container នៅក្នុង Pod ។

*   **មើល Logs របស់ Container ក្នុង Pod មួយ:**
    ```bash
    kubectl logs my-pod
    ```
    *   **ការពន្យល់:** ប្រសិនបើ Pod មាន Container តែមួយ វានឹងបង្ហាញ Logs របស់វា។

*   **មើល Logs របស់ Container ជាក់លាក់មួយក្នុង Pod ដែលមានច្រើន Containers:**
    ```bash
    kubectl logs my-pod -c my-container
    ```

*   **តាមដាន Logs ក្នុងពេលជាក់ស្តែង (Follow Logs):**
    ```bash
    kubectl logs -f my-pod
    ```

#### ៤. `kubectl exec` – ដំណើរការ Command ក្នុង Container

ប្រើដើម្បីដំណើរការ Command នៅក្នុង Container ដែលកំពុងដំណើរការ។

*   **ដំណើរការ `ls /` នៅក្នុង Container នៃ Pod មួយ:**
    ```bash
    kubectl exec my-pod -- ls /
    ```
    *   **ការពន្យល់:** `--` គឺជាសញ្ញាបំបែករវាង Command របស់ `kubectl` និង Command ដែលអ្នកចង់ដំណើរការនៅក្នុង Container ។

*   **បើក Interactive Shell នៅក្នុង Container:**
    ```bash
    kubectl exec -it my-pod -- bash
    ```
    *   **ការពន្យល់:** `-i` សម្រាប់ Interactive, `-t` សម្រាប់ TTY (pseudo-terminal)។ នេះអនុញ្ញាតឱ្យអ្នកចូលទៅក្នុង Container ហើយដំណើរការ Commands ដូចជាអ្នកនៅក្នុងម៉ាស៊ីននោះផ្ទាល់។

#### ៥. `kubectl apply` – Deploy និង Update Resources

ប្រើដើម្បីបង្កើត ឬ Update Resources របស់ Kubernetes ដោយប្រើ File YAML ។

*   **បង្កើត ឬ Update Resource ពី File YAML:**
    ```bash
    kubectl apply -f my-deployment.yaml
    ```
    *   **ការពន្យល់:** `apply` គឺជា Command ដែលមានអនុភាពខ្លាំង ព្រោះវាអាចបង្កើត Resources ថ្មី ឬ Update Resources ដែលមានស្រាប់។ Kubernetes នឹងរកឃើញភាពខុសគ្នារវាង File YAML និង Current State របស់ Resource ហើយធ្វើការកែប្រែដោយស្វ័យប្រវត្តិ។

#### ៦. `kubectl delete` – លុប Resources

ប្រើដើម្បីលុប Resources របស់ Kubernetes ។

*   **លុប Pod មួយដោយឈ្មោះ:**
    ```bash
    kubectl delete pod my-pod
    ```

*   **លុប Resource ពី File YAML:**
    ```bash
    kubectl delete -f my-deployment.yaml
    ```

*   **លុប Resources ទាំងអស់នៃប្រភេទមួយ (ប្រយ័ត្ន!):**
    ```bash
    kubectl delete pods --all
    ```

#### ៧. `kubectl create` – បង្កើត Resources

ប្រើដើម្បីបង្កើត Resources របស់ Kubernetes (ជាទូទៅត្រូវបានជំនួសដោយ `kubectl apply`)។

*   **បង្កើត Namespace មួយ:**
    ```bash
    kubectl create namespace my-namespace
    ```

#### ៨. `kubectl config` – គ្រប់គ្រង Kubeconfig File

ប្រើដើម្បីគ្រប់គ្រង Configuration File របស់ `kubectl` (ជាធម្មតា `~/.kube/config`) ដែលមានព័ត៌មានអំពី Clusters, Users, និង Contexts ។

*   **មើល Configuration បច្ចុប្បន្ន:**
    ```bash
    kubectl config view
    ```

*   **ប្តូរ Context បច្ចុប្បន្ន:**
    ```bash
    kubectl config use-context minikube
    ```

### ការប្រើប្រាស់ Namespaces

Namespaces ជួយបំបែក Resources នៅក្នុង Cluster តែមួយ។

*   **មើល Namespaces ទាំងអស់:**
    ```bash
    kubectl get namespaces
    ```

*   **មើល Resources ក្នុង Namespace ជាក់លាក់:**
    ```bash
    kubectl get pods -n my-namespace
    ```

*   **កំណត់ Namespace លំនាំដើម (Default Namespace) សម្រាប់ Context បច្ចុប្បន្ន:**
    ```bash
    kubectl config set-context --current --namespace=my-namespace
    ```

### សរុបមក

`kubectl` គឺជាឧបករណ៍ដ៏មានឥទ្ធិពល និងចាំបាច់បំផុតសម្រាប់ការធ្វើការជាមួយ Kubernetes ។ ការយល់ដឹង និងការអនុវត្ត Commands ទាំងនេះនឹងផ្តល់ឱ្យអ្នកនូវមូលដ្ឋានគ្រឹះដ៏រឹងមាំមួយក្នុងការគ្រប់គ្រង Kubernetes Cluster និង Deploy កម្មវិធីរបស់អ្នក។