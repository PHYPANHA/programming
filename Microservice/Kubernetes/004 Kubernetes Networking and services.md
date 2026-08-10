# ជំពូកទី ៤៖ បណ្ដាញ និងការភ្ជាប់ទំនាក់ទំនង (Networking & Services)

## ៤.១ អ្វីទៅជា Kubernetes Services?

នៅក្នុងជំពូកមុន យើងបានរៀនអំពី Pods, ReplicaSets, Deployments, និង Namespaces។ យើងដឹងថា Pods គឺ Ephemeral (បណ្ដោះអាសន្ន) ដែលអាចត្រូវបានបង្កើត ឬលុបចោលបានគ្រប់ពេល ហើយ IP Address របស់ពួកវាក៏អាចផ្លាស់ប្តូរផងដែរ។ បញ្ហានេះបង្កការលំបាកដល់កម្មវិធីដែលត្រូវទំនាក់ទំនងគ្នា ព្រោះពួកវាមិនអាចពឹងផ្អែកលើ IP Address របស់ Pod ណាមួយបានទេ។

ដើម្បីដោះស្រាយបញ្ហានេះ Kubernetes បានណែនាំនូវគំនិតនៃ **Service** ។

### អ្វីទៅជា Service?

**Service** គឺជា Abstraction មួយនៅក្នុង Kubernetes ដែលកំណត់ Set នៃ Pods ឡូជីខល និង Policy សម្រាប់ Access ទៅកាន់ពួកវា។ Service ផ្តល់ជូននូវ IP Address និម្មិត (Virtual IP) និង DNS Name ថេរមួយ ដែលអនុញ្ញាតឱ្យកម្មវិធីផ្សេងទៀតអាច Access ទៅកាន់ Pods ដែលស្ថិតនៅពីក្រោយ Service នោះបាន ទោះបីជា Pods ទាំងនោះត្រូវបានបង្កើតឡើងវិញ ឬផ្លាស់ប្តូរ IP Address ក៏ដោយ។

និយាយឱ្យសាមញ្ញ Service ដើរតួជា **Internal Load Balancer** នៅក្នុង Kubernetes Cluster ។ វាដើរតួជាចំណុចចូលប្រើប្រាស់ (Entry Point) ថេរសម្រាប់ Pods មួយក្រុម។

### ហេតុអ្វីត្រូវប្រើ Services?

1.  **Service Discovery:** Pods មិនចាំបាច់ដឹង IP Address របស់ Pod ផ្សេងទៀតនោះទេ។ ពួកវាគ្រាន់តែប្រើ DNS Name របស់ Service ដើម្បីទំនាក់ទំនង។
2.  **Load Balancing:** Service ចែកចាយ Traffic ទៅកាន់ Pods ជាច្រើនដែលស្ថិតនៅពីក្រោយវា ដែលធានានូវ High Availability និង Scalability ។
3.  **Connectivity:** អនុញ្ញាតឱ្យកម្មវិធីនៅក្នុង Pods ទំនាក់ទំនងគ្នាទៅវិញទៅមក ហើយក៏អនុញ្ញាតឱ្យ External Traffic Access ទៅកាន់កម្មវិធីនៅក្នុង Cluster ផងដែរ។
4.  **Decoupling:** បំបែក Frontend ពី Backend ។ Frontend គ្រាន់តែដឹងពី Service របស់ Backend ហើយមិនចាំបាច់ដឹងពីចំនួន ឬ IP Address របស់ Backend Pods នោះទេ។

### របៀបដែល Services ដំណើរការ

Service ប្រើ **Labels** និង **Selectors** ដើម្បីស្វែងរក Pods ដែលវាគួរតែបញ្ជូន Traffic ទៅកាន់។ នៅពេលអ្នកបង្កើត Service, អ្នកកំណត់ Selector ដែលផ្គូផ្គង Labels របស់ Pods ដែលអ្នកចង់ឱ្យ Service នោះគ្រប់គ្រង។

<img src="https://kubernetes.io/docs/images/docs/services.png" alt="Kubernetes Service Diagram" width="500"/>

*   **Selector:** កំណត់ថា Pods ណាដែលជាផ្នែកនៃ Service ។
*   **Target Port:** Port ដែល Service កំពុងរង់ចាំ Connection ចូល។
*   **Pod Port:** Port ដែល Container នៅក្នុង Pod ពិតជាស្តាប់ (Listening) ។

### ឧទាហរណ៍ Service YAML

យើងនឹងបង្កើត Deployment សម្រាប់ Nginx ចំនួន 3 Pods ហើយបន្ទាប់មកបង្កើត Service ដើម្បី Expose Nginx Web Server ។

**១. Nginx Deployment (nginx-deployment-with-labels.yaml):**

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-app-deployment
  labels:
    app: nginx
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx
      tier: frontend # បន្ថែម Label ថ្មីសម្រាប់ Service Selector
  template:
    metadata:
      labels:
        app: nginx
        tier: frontend # Labels នៅក្នុង template ត្រូវតែត្រូវគ្នាជាមួយ selector
    spec:
      containers:
      - name: nginx-container
        image: nginx:latest
        ports:
        - containerPort: 80
```

រក្សាទុកទៅក្នុង `nginx-deployment-with-labels.yaml` រួច Deploy:

```bash
kubectl apply -f nginx-deployment-with-labels.yaml
```

ផ្ទៀងផ្ទាត់ Pods:

```bash
kubectl get pods -l tier=frontend
```

**២. Nginx Service (nginx-service.yaml):**

```yaml
apiVersion: v1 # កំណត់ Kubernetes API version
kind: Service # កំណត់ប្រភេទ Resource នេះគឺ Service
metadata:
  name: nginx-service # ឈ្មោះរបស់ Service
spec:
  selector: # Service Selector ត្រូវតែផ្គូផ្គង Labels របស់ Pods
    app: nginx
    tier: frontend
  ports:
    - protocol: TCP
      port: 80 # Port ដែល Service នឹងបើក (Internal Cluster IP)
      targetPort: 80 # Port ដែល Container នៅក្នុង Pod ស្តាប់ (Listening)
  type: ClusterIP # ប្រភេទ Service (នឹងរៀនលម្អិតក្នុងផ្នែកបន្ទាប់)
```

**ការពន្យល់ពី YAML Fields (សម្រាប់ Service):**

*   `apiVersion`: សម្រាប់ Service គឺ `v1` ។
*   `kind`: `Service` ។
*   `metadata.name`: ឈ្មោះរបស់ Service ។
*   `spec.selector`: ជា Field សំខាន់ដែលប្រាប់ Service ពី Pods ណាដែលវាគួរតែបញ្ជូន Traffic ទៅកាន់។ ក្នុងឧទាហរណ៍នេះ Service នឹងបញ្ជូន Traffic ទៅកាន់ Pods ណាដែលមាន Label `app: nginx` និង `tier: frontend` ។
*   `spec.ports`: កំណត់ Port Mapping សម្រាប់ Service ។
    *   `protocol`: ជាធម្មតា `TCP` (ឬ `UDP`) ។
    *   `port`: Port ដែល Service នឹង Expose ។ នេះជា Port ដែលកម្មវិធីផ្សេងទៀតនៅក្នុង Cluster នឹងប្រើដើម្បីភ្ជាប់ទៅ Service នេះ។
    *   `targetPort`: Port ដែល Container នៅក្នុង Pod ពិតជាកំពុងស្តាប់ (Listening) ។
*   `spec.type`: កំណត់ប្រភេទរបស់ Service ។ `ClusterIP` គឺជា Default ហើយត្រូវបានប្រើសម្រាប់ Access ពីខាងក្នុង Cluster ។ យើងនឹងរៀនអំពីប្រភេទផ្សេងទៀតនៅក្នុងផ្នែកបន្ទាប់។

រក្សាទុកទៅក្នុង `nginx-service.yaml` រួច Deploy:

```bash
kubectl apply -f nginx-service.yaml
```

### ការផ្ទៀងផ្ទាត់ Service

1.  **មើល Services ទាំងអស់:**
    ```bash
    kubectl get services
    ```
    អ្នកគួរតែឃើញ `nginx-service` ជាមួយនឹង `TYPE` ជា `ClusterIP` និង `CLUSTER-IP` (Internal IP) ។

    ```bash
    # ឧទាហរណ៍ Output
    NAME            TYPE        CLUSTER-IP     EXTERNAL-IP   PORT(S)   AGE
    kubernetes      ClusterIP   10.96.0.1      <none>        443/TCP   2d
    nginx-service   ClusterIP   10.96.123.45   <none>        80/TCP    30s
    ```

2.  **ពិនិត្យមើល Endpoints របស់ Service:**
    ```bash
    kubectl get endpoints nginx-service
    ```
    *   **ការពន្យល់:** Endpoints បង្ហាញពី IP Address របស់ Pods ដែល Service កំពុង Load Balance ។ អ្នកគួរតែឃើញ IP Address របស់ Pods Nginx ទាំង 3 ។

### ការទំនាក់ទំនងជាមួយ Service (ក្នុង Cluster)

Pods នៅក្នុង Cluster អាចទំនាក់ទំនងជាមួយ `nginx-service` ដោយប្រើ DNS Name របស់វា (`nginx-service`) ឬ Cluster IP របស់វា។

**ឧទាហរណ៍ (ការបង្កើត Temp Pod ដើម្បីសាកល្បង Connection):**

```bash
kubectl run -it --rm --image=alpine:latest test-client -- sh
```

នៅពេលអ្នកនៅក្នុង Shell របស់ `test-client` Pod:

```bash
# ព្យាយាម Ping ទៅកាន់ Service DNS Name
ping nginx-service

# ព្យាយាម Access Nginx Web Server
wget -O- nginx-service
```

អ្នកគួរតែឃើញ HTML Content របស់ Nginx Default Page ។ បន្ទាប់ពីសាកល្បងរួច វាយ `exit` ដើម្បីចេញពី Pod ។

### សរុបមក

Kubernetes Services គឺជាផ្នែកមួយដ៏សំខាន់នៃ Networking នៅក្នុង Kubernetes ។ ពួកវាផ្តល់នូវវិធីសាស្រ្តមួយដែល Reliable និង Scalable សម្រាប់ Pods ក្នុងការទំនាក់ទំនងគ្នាទៅវិញទៅមក និងសម្រាប់ External Traffic ក្នុងការ Access ទៅកាន់កម្មវិធីនៅក្នុង Cluster ។ នៅក្នុងផ្នែកបន្ទាប់ យើងនឹងរៀនអំពីប្រភេទ Services ផ្សេងៗគ្នា និងពេលណាដែលត្រូវប្រើពួកវានីមួយៗ។

## ៤.២ ប្រភេទនៃ Services: ClusterIP, NodePort, និង LoadBalancer

នៅក្នុងផ្នែកមុន យើងបានរៀនថា Service ផ្តល់នូវ Static IP និង DNS Name សម្រាប់ក្រុម Pods។ Kubernetes ផ្តល់ជូននូវប្រភេទ Services ជាច្រើន ដែលនីមួយៗមានគោលបំណង និងរបៀប Expose កម្មវិធីទៅកាន់បណ្តាញខុសៗគ្នា។ ការជ្រើសរើសប្រភេទ Service ត្រឹមត្រូវគឺសំខាន់សម្រាប់របៀបដែលកម្មវិធីរបស់អ្នកត្រូវបាន Access ។

ប្រភេទ Service សំខាន់ៗមានដូចខាងក្រោម៖

1.  **ClusterIP (Default Type)**
2.  **NodePort**
3.  **LoadBalancer**


### ១. ClusterIP (Default Type)

**ClusterIP** គឺជាប្រភេទ Service លំនាំដើម (default) ។ វា Expose Service នៅលើ Internal IP របស់ Cluster ។ នេះមានន័យថា Service អាច Access បានតែពីខាងក្នុង Cluster ប៉ុណ្ណោះ។ ClusterIP ត្រូវបានប្រើជាទូទៅសម្រាប់ Internal Services ដែល Pods នៅក្នុង Cluster ត្រូវការទំនាក់ទំនងគ្នាទៅវិញទៅមក (ឧទាហរណ៍ Backend Database ឬ Microservice មួយទំនាក់ទំនងទៅ Microservice មួយទៀត) ។

<img src="https://kubernetes.io/docs/images/docs/services-cluster-ip.png" alt="Kubernetes ClusterIP Service" width="400"/>

**លក្ខណៈសំខាន់ៗ:**

*   ផ្តល់នូវ Internal IP Address តែមួយគត់សម្រាប់ Service នៅក្នុង Cluster ។
*   មិនអាច Access បានពីខាងក្រៅ Cluster ដោយផ្ទាល់ទេ ។
*   ល្អឥតខ្ចោះសម្រាប់ Internal Communication រវាង Microservices ។

**ឧទាហរណ៍ YAML (ClusterIP Service):**

យើងបានប្រើឧទាហរណ៍នេះរួចហើយនៅក្នុងផ្នែក ៤.១ ។

```yaml
apiVersion: v1
kind: Service
metadata:
  name: my-nginx-clusterip-service
spec:
  selector:
    app: nginx
    tier: frontend
  ports:
    - protocol: TCP
      port: 80
      targetPort: 80
  type: ClusterIP # បញ្ជាក់ប្រភេទជា ClusterIP (ឬមិនបញ្ជាក់ ព្រោះវាជា default)
```

**របៀប Deploy និងផ្ទៀងផ្ទាត់:**

1.  **ត្រូវប្រាកដថា Deployment `nginx-app-deployment` ដែលមាន Label `app: nginx` និង `tier: frontend` កំពុងដំណើរការ:**
    ```bash
    kubectl apply -f nginx-deployment-with-labels.yaml # (File ពីផ្នែក 4.1)
    kubectl get pods -l app=nginx,tier=frontend
    ```

2.  **Deploy ClusterIP Service:**
    ```bash
    kubectl apply -f my-nginx-clusterip-service.yaml # រក្សាទុក YAML ខាងលើ
    ```

3.  **មើល Service:**
    ```bash
    kubectl get service my-nginx-clusterip-service
    ```
    អ្នកនឹងឃើញ `CLUSTER-IP` ដែលអាចប្រើសម្រាប់ Access ពី Pod ផ្សេងទៀតនៅក្នុង Cluster ។

### ២. NodePort

**NodePort** Service Expose កម្មវិធីរបស់អ្នកនៅលើ Port ជាក់លាក់មួយនៅលើ Node នីមួយៗនៅក្នុង Cluster ។ នេះមានន័យថា Traffic ពីខាងក្រៅ Cluster អាច Access ទៅកាន់ Service របស់អ្នកដោយប្រើ IP Address របស់ Node ណាមួយ និង Port ដែលបានកំណត់។

Kubernetes នឹងបើក Port ជាក់លាក់មួយ (NodePort) នៅលើ Node ទាំងអស់។ Traffic ដែលចូលទៅកាន់ Port នេះនៅលើ Node ណាមួយ នឹងត្រូវបានបញ្ជូនបន្តទៅកាន់ Service របស់អ្នក ដែលបន្ទាប់មក Load Balance ទៅកាន់ Pods ដែលពាក់ព័ន្ធ។

<img src="https://kubernetes.io/docs/images/docs/services-node-port.png" alt="Kubernetes NodePort Service" width="400"/>

**លក្ខណៈសំខាន់ៗ:**

*   Expose Service នៅលើ Port ជាក់លាក់មួយ (រវាង 30000-32767 ដោយ Default) នៅលើ Node នីមួយៗ។
*   អាច Access បានពីខាងក្រៅ Cluster ដោយប្រើ `NodeIP:NodePort` ។
*   NodePort Services ក៏បង្កើត ClusterIP Service ខាងក្នុងមួយដោយស្វ័យប្រវត្តិផងដែរ។
*   ល្អសម្រាប់ Environment ដែលមិនមែនជា Production ឬនៅពេលអ្នកមិនមាន Load Balancer នៅក្នុង Infrastructure របស់អ្នក។

**ឧទាហរណ៍ YAML (NodePort Service):**

```yaml
apiVersion: v1
kind: Service
metadata:
  name: my-nginx-nodeport-service
spec:
  selector:
    app: nginx
    tier: frontend
  ports:
    - protocol: TCP
      port: 80 # Port របស់ Service
      targetPort: 80 # Port របស់ Container
      nodePort: 30080 # (Optional) កំណត់ NodePort ជាក់លាក់ (បើមិនកំណត់ វានឹងជ្រើសរើសដោយស្វ័យប្រវត្តិ)
  type: NodePort # បញ្ជាក់ប្រភេទជា NodePort
```

**របៀប Deploy និងផ្ទៀងផ្ទាត់:**

1.  **Deploy NodePort Service:**
    ```bash
    kubectl apply -f my-nginx-nodeport-service.yaml # រក្សាទុក YAML ខាងលើ
    ```

2.  **មើល Service:**
    ```bash
    kubectl get service my-nginx-nodeport-service
    ```
    អ្នកនឹងឃើញ `CLUSTER-IP`, `EXTERNAL-IP` ជា `<none>`, `PORT(S)` (ឧទាហរណ៍ `80:30080/TCP`) ដែលបង្ហាញពី NodePort ដែលបានបើក។

    ```bash
    # ឧទាហរណ៍ Output
    NAME                      TYPE        CLUSTER-IP      EXTERNAL-IP   PORT(S)        AGE
    my-nginx-nodeport-service   NodePort    10.103.181.82   <none>        80:30080/TCP   1m
    ```

3.  **ស្វែងរក IP Address របស់ Node:**
    ```bash
    minikube ip # ប្រសិនបើអ្នកកំពុងប្រើ Minikube
    # ឬ
    kubectl get nodes -o wide # សម្រាប់ Cluster ពិតប្រាកដ
    ```
    ឧបមាថា IP របស់ Node គឺ `192.168.49.2` ។

4.  **Access កម្មវិធីពីខាងក្រៅ Cluster:**
    បើក Browser របស់អ្នកហើយវាយ `http://<NodeIP>:<NodePort>` (ឧទាហរណ៍ `http://192.168.49.2:30080`) ។ អ្នកគួរតែឃើញទំព័រ Nginx Default ។

### ៣. LoadBalancer

**LoadBalancer** Service គឺជាប្រភេទ Service ដ៏មានឥទ្ធិពលបំផុតសម្រាប់ Expose កម្មវិធីទៅកាន់ Traffic ខាងក្រៅនៅក្នុង Public Cloud Environments (ដូចជា Google Cloud, AWS, Azure)។ នៅពេលអ្នកបង្កើត LoadBalancer Service នៅក្នុង Cloud Provider Kubernetes នឹងស្នើសុំឱ្យ Cloud Provider បង្កើត External Load Balancer សម្រាប់ Service របស់អ្នកដោយស្វ័យប្រវត្តិ។ External Load Balancer នេះនឹងមាន External IP Address ដែលអាច Access បានពី Internet ។

<img src="https://kubernetes.io/docs/images/docs/services-load-balancer.png" alt="Kubernetes LoadBalancer Service" width="400"/>

**លក្ខណៈសំខាន់ៗ:**

*   ផ្តល់នូវ External IP Address ជាក់ស្តែងពី Cloud Provider របស់អ្នក។
*   Traffic ត្រូវបាន Load Balance ដោយ External Load Balancer របស់ Cloud Provider ទៅកាន់ Nodes ក្នុង Cluster ដែលបន្ទាប់មកបញ្ជូនបន្តទៅកាន់ Pods ។
*   LoadBalancer Services ក៏បង្កើត NodePort និង ClusterIP Services ខាងក្នុងដោយស្វ័យប្រវត្តិផងដែរ។
*   ល្អឥតខ្ចោះសម្រាប់ Production Applications ដែលត្រូវការ High Availability និង External Access ។
*   **ចំណាំ:** LoadBalancer Services អាចមានតម្លៃថ្លៃបន្តិចអាស្រ័យលើ Cloud Provider ។

**ឧទាហរណ៍ YAML (LoadBalancer Service):**

```yaml
apiVersion: v1
kind: Service
metadata:
  name: my-nginx-loadbalancer-service
spec:
  selector:
    app: nginx
    tier: frontend
  ports:
    - protocol: TCP
      port: 80 # Port ដែល Load Balancer ស្តាប់
      targetPort: 80 # Port របស់ Container
  type: LoadBalancer # បញ្ជាក់ប្រភេទជា LoadBalancer
```

**របៀប Deploy និងផ្ទៀងផ្ទាត់ (នៅលើ Minikube):**

នៅលើ Minikube, `LoadBalancer` Service នឹងមិនបង្កើត External Load Balancer ពិតប្រាកដដូច Cloud Provider នោះទេ។ ផ្ទុយទៅវិញ Minikube នឹងផ្តល់នូវ External IP ដែលអ្នកអាចប្រើដើម្បី Access Service ។

1.  **Deploy LoadBalancer Service:**
    ```bash
    kubectl apply -f my-nginx-loadbalancer-service.yaml # រក្សាទុក YAML ខាងលើ
    ```

2.  **មើល Service:**
    ```bash
    kubectl get service my-nginx-loadbalancer-service
    ```
    អ្នកនឹងឃើញ `CLUSTER-IP` និង `EXTERNAL-IP` ។ នៅលើ Minikube, `EXTERNAL-IP` ជាធម្មតានឹងជា IP Address របស់ Minikube Node ដូចគ្នានឹង `minikube ip` ដែរ។

    ```bash
    # ឧទាហរណ៍ Output (នៅលើ Minikube)
    NAME                          TYPE           CLUSTER-IP      EXTERNAL-IP     PORT(S)        AGE
    my-nginx-loadbalancer-service   LoadBalancer   10.106.143.18   192.168.49.2    80:30256/TCP   1m
    ```

3.  **Access កម្មវិធីពីខាងក្រៅ Cluster:**
    បើក Browser របស់អ្នកហើយវាយ `http://<External-IP>` (ឧទាហរណ៍ `http://192.168.49.2`) ។ អ្នកគួរតែឃើញទំព័រ Nginx Default ។

### ការប្រៀបធៀបប្រភេទ Services

| លក្ខណៈ             | ClusterIP                        | NodePort                               | LoadBalancer                             |
| :------------------- | :------------------------------- | :------------------------------------- | :--------------------------------------- |
| **ការចូលប្រើប្រាស់** | តែពីខាងក្នុង Cluster ប៉ុណ្ណោះ     | ពីខាងក្រៅ Cluster ដោយ `NodeIP:NodePort` | ពី Internet ដោយ `External-IP`          |
| **IP Address**       | Internal Cluster IP             | Node IP + Static NodePort              | External IP ពី Cloud Provider           |
| **ការប្រើប្រាស់**     | Internal Microservices Communication | Dev/Test, Non-Production, On-Premise   | Production, Public Cloud, Internet-facing |
| **តម្លៃ**           | ឥតគិតថ្លៃ                        | ឥតគិតថ្លៃ                              | អាចមានតម្លៃ (អាស្រ័យលើ Cloud Provider) |

### សរុបមក

ការយល់ដឹងអំពីប្រភេទ Services ផ្សេងៗគ្នាគឺមានសារៈសំខាន់ណាស់សម្រាប់ការរចនា Architecture របស់កម្មវិធីរបស់អ្នកនៅក្នុង Kubernetes ។

*   ប្រើ **ClusterIP** សម្រាប់ Internal Services ដែលមិនចាំបាច់ Access ពីខាងក្រៅ Cluster ។
*   ប្រើ **NodePort** សម្រាប់ Environments ក្នុងស្រុក ឬនៅពេលអ្នកត្រូវការ Access កម្មវិធីពីខាងក្រៅ Cluster ដោយមិនចាំបាច់មាន Cloud Load Balancer ។
*   ប្រើ **LoadBalancer** សម្រាប់ Production Applications ដែលត្រូវការ Public IP Address និង External Load Balancing ពី Cloud Provider ។

## ៤.៣ Ingress (External Access with Advanced Routing)

នៅក្នុងផ្នែកមុន យើងបានស្វែងយល់អំពី Service Types ដូចជា ClusterIP, NodePort, និង LoadBalancer។

*   **ClusterIP** សម្រាប់ Internal Access តែប៉ុណ្ណោះ។
*   **NodePort** អនុញ្ញាតឱ្យ External Access តាមរយៈ IP របស់ Node និង Port ដែលបានកំណត់។
*   **LoadBalancer** ផ្តល់នូវ External IP ជាមួយនឹង Load Balancing សម្រាប់ Public Cloud Environments។

ខណៈពេលដែល LoadBalancer Service មានប្រយោជន៍ វាមានដែនកំណត់មួយចំនួន៖

1.  **តម្លៃ (Cost):** Cloud Load Balancer នីមួយៗដែលត្រូវបាន Provision សម្រាប់ Service អាចមានតម្លៃថ្លៃ។ ប្រសិនបើអ្នកមានកម្មវិធី (Applications) ជាច្រើនដែលត្រូវ Expose វាអាចចំណាយអស់ច្រើន។
2.  **ការកំណត់រចនាសម្ព័ន្ធ (Configuration):** LoadBalancer Service មួយជាធម្មតាត្រូវបានភ្ជាប់ទៅនឹង Service តែមួយ។ អ្នកមិនអាចកំណត់ Domain Name ឬ Path-based Routing បានទេ។

ដើម្បីដោះស្រាយបញ្ហាទាំងនេះ Kubernetes ផ្តល់នូវ **Ingress** ។

### អ្វីទៅជា Ingress?

**Ingress** គឺជា API Object របស់ Kubernetes ដែលគ្រប់គ្រង External Access ទៅកាន់ Services នៅក្នុង Cluster ជាទូទៅតាមរយៈ HTTP/HTTPS។ Ingress ផ្តល់នូវ HTTP Load Balancing, SSL Termination, និង Name-based Virtual Hosting ។

និយាយឱ្យសាមញ្ញ Ingress ដើរតួជា **Reverse Proxy** ឬ **API Gateway** សម្រាប់ Traffic ដែលចូលទៅកាន់ Cluster របស់អ្នក។ វាអនុញ្ញាតឱ្យអ្នករួមបញ្ចូល External Entry Point មួយសម្រាប់ Service ជាច្រើនដោយប្រើ Configuration ដ៏ងាយស្រួល។

<img src="https://kubernetes.io/docs/images/docs/ingress.png" alt="Kubernetes Ingress Diagram" width="500"/>

**មុខងារសំខាន់ៗរបស់ Ingress:**

*   **External Access:** អនុញ្ញាតឱ្យ Traffic ពីខាងក្រៅ Cluster (ឧទាហរណ៍ Web Browser) អាច Access ទៅកាន់ Services របស់អ្នក។
*   **Load Balancing:** ចែកចាយ Traffic ទៅកាន់ Services ផ្សេងៗគ្នាដោយផ្អែកលើ Rules ដែលអ្នកកំណត់។
*   **Name-based Virtual Hosting:** កំណត់ Hostnames ផ្សេងគ្នាដើម្បី Route Traffic ទៅកាន់ Services ផ្សេងគ្នា (ឧទាហរណ៍ `app1.example.com` ទៅ Service A, `app2.example.com` ទៅ Service B)។
*   **Path-based Routing:** កំណត់ Paths ផ្សេងគ្នាដើម្បី Route Traffic ទៅកាន់ Services ផ្សេងគ្នា (ឧទាហរណ៍ `example.com/app1` ទៅ Service A, `example.com/app2` ទៅ Service B)។
*   **SSL/TLS Termination:** គ្រប់គ្រង SSL Certificates និង Decrypt Traffic មុនពេលបញ្ជូនវាទៅកាន់ Services របស់អ្នក។

### Ingress Controller

**Ingress** គឺជា API Object មួយ ប៉ុន្តែវាមិនដំណើរការដោយខ្លួនឯងនោះទេ។ ដើម្បីឱ្យ Ingress ដំណើរការ អ្នកត្រូវការ **Ingress Controller** ដែលកំពុងដំណើរការនៅក្នុង Cluster របស់អ្នក។ Ingress Controller គឺជា Controller ដែលមើល Ingress Resource ហើយបន្ទាប់មកកំណត់រចនាសម្ព័ន្ធ Load Balancer (ឧទាហរណ៍ Nginx, HAProxy, Envoy) តាម Rules ដែលបានកំណត់នៅក្នុង Ingress Object ។

Ingress Controller ដ៏ពេញនិយមមួយគឺ **Nginx Ingress Controller** ។

### ការដំឡើង Nginx Ingress Controller (នៅលើ Minikube)

នៅលើ Minikube, អ្នកអាចបើកដំណើរការ Ingress Addon បានយ៉ាងងាយស្រួល:

1.  **បើកដំណើរការ Ingress Addon:**
    ```bash
    minikube addons enable ingress
    ```
    *   **ការពន្យល់:** Command នេះនឹង Deploy Nginx Ingress Controller ទៅក្នុង Minikube Cluster របស់អ្នក។

2.  **ផ្ទៀងផ្ទាត់ថា Ingress Controller កំពុងដំណើរការ:**
    ```bash
    kubectl get pods -n ingress-nginx
    kubectl get service -n ingress-nginx
    ```
    អ្នកគួរតែឃើញ Pod មួយ (ឬច្រើន) ដែលមានឈ្មោះ `ingress-nginx-controller-xxxxx` កំពុងដំណើរការ ហើយ Service ប្រភេទ `LoadBalancer` នៅក្នុង Namespace `ingress-nginx` ។ Minikube នឹងផ្តល់ `EXTERNAL-IP` សម្រាប់ Service នេះ ដែលជា IP របស់ Minikube Node ។

### ឧទាហរណ៍ Ingress YAML (Name-based Virtual Hosting)

យើងនឹងបង្កើត Deployment Nginx ពីរផ្សេងគ្នា និង Service ពីរផ្សេងគ្នា បន្ទាប់មកប្រើ Ingress ដើម្បី Route Traffic ដោយផ្អែកលើ Hostname ។

1.  **Nginx Deployment សម្រាប់ `app1.example.com` (nginx-app1-deployment.yaml):**
    ```yaml
    apiVersion: apps/v1
    kind: Deployment
    metadata:
      name: nginx-app1-deployment
      labels:
        app: nginx-app1
    spec:
      replicas: 1
      selector:
        matchLabels:
          app: nginx-app1
      template:
        metadata:
          labels:
            app: nginx-app1
        spec:
          containers:
          - name: nginx-container
            image: nginxdemos/hello:plain-text # Image ផ្សេងដើម្បីងាយសម្គាល់
            ports:
            - containerPort: 80
    ```

2.  **Service សម្រាប់ `nginx-app1` (nginx-app1-service.yaml):**
    ```yaml
    apiVersion: v1
    kind: Service
    metadata:
      name: nginx-app1-service
    spec:
      selector:
        app: nginx-app1
      ports:
        - protocol: TCP
          port: 80
          targetPort: 80
      type: ClusterIP # ប្រើ ClusterIP ព្រោះ Ingress នឹង Access វាពីខាងក្នុង Cluster
    ```

3.  **Nginx Deployment សម្រាប់ `app2.example.com` (nginx-app2-deployment.yaml):**
    ```yaml
    apiVersion: apps/v1
    kind: Deployment
    metadata:
      name: nginx-app2-deployment
      labels:
        app: nginx-app2
    spec:
      replicas: 1
      selector:
        matchLabels:
          app: nginx-app2
      template:
        metadata:
          labels:
            app: nginx-app2
        spec:
          containers:
          - name: nginx-container
            image: nginx:latest # Image ខុសគ្នា
            ports:
            - containerPort: 80
    ```

4.  **Service សម្រាប់ `nginx-app2` (nginx-app2-service.yaml):**
    ```yaml
    apiVersion: v1
    kind: Service
    metadata:
      name: nginx-app2-service
    spec:
      selector:
        app: nginx-app2
      ports:
        - protocol: TCP
          port: 80
          targetPort: 80
      type: ClusterIP
    ```

5.  **Ingress Resource (my-example-ingress.yaml):**
    ```yaml
    apiVersion: networking.k8s.io/v1
    kind: Ingress
    metadata:
      name: example-ingress
      annotations:
        nginx.ingress.kubernetes.io/rewrite-target: /
    spec:
      rules:
      - host: app1.example.com
        http:
          paths:
          - path: /
            pathType: Prefix
            backend:
              service:
                name: nginx-app1-service
                port:
                  number: 80
      - host: app2.example.com
        http:
          paths:
          - path: /
            pathType: Prefix
            backend:
              service:
                name: nginx-app2-service
                port:
                  number: 80
    ```

**ការពន្យល់ពី Ingress YAML Fields:**

*   `apiVersion`: សម្រាប់ Ingress គឺ `networking.k8s.io/v1` ។
*   `kind`: `Ingress` ។
*   `metadata.name`: ឈ្មោះរបស់ Ingress ។
*   `annotations`: ប្រើសម្រាប់ផ្តល់ Configuration បន្ថែមទៅ Ingress Controller (ឧទាហរណ៍ `nginx.ingress.kubernetes.io/rewrite-target: /` ត្រូវបានប្រើសម្រាប់ Nginx Ingress Controller ដើម្បី rewrite Path)។
*   `spec.rules`: កំណត់ Rules សម្រាប់ Routing Traffic ។
    *   `host`: កំណត់ Hostname ដែល Traffic ត្រូវគ្នា។
    *   `http.paths`: កំណត់ Rules ដោយផ្អែកលើ HTTP Path ។
        *   `path`: Path ដែល Traffic ត្រូវគ្នា (ឧទាហរណ៍ `/` ឬ `/api`) ។
        *   `pathType`: របៀបដែល Path ត្រូវបានផ្គូផ្គង (ឧទាហរណ៍ `Prefix`, `Exact`, `ImplementationSpecific`) ។
        *   `backend`: កំណត់ Service ដែល Traffic នឹងត្រូវបាន Route ទៅកាន់។
            *   `service.name`: ឈ្មោះរបស់ Service ។
            *   `service.port.number`: Port របស់ Service ។

### របៀប Deploy និងផ្ទៀងផ្ទាត់ Ingress

1.  **Deploy Deployments និង Services ទាំងបួន:**
    ```bash
    kubectl apply -f nginx-app1-deployment.yaml
    kubectl apply -f nginx-app1-service.yaml
    kubectl apply -f nginx-app2-deployment.yaml
    kubectl apply -f nginx-app2-service.yaml
    ```

2.  **Deploy Ingress Resource:**
    ```bash
    kubectl apply -f my-example-ingress.yaml
    ```

3.  **មើល Ingress:**
    ```bash
    kubectl get ingress
    ```
    អ្នកគួរតែឃើញ Ingress របស់អ្នកជាមួយនឹង `ADDRESS` ដែលជា IP របស់ Minikube Node (ដូចគ្នានឹង `minikube ip`) ។

    ```bash
    # ឧទាហរណ៍ Output
    NAME              CLASS    HOSTS                          ADDRESS        PORTS   AGE
    example-ingress   <none>   app1.example.com,app2.example.com   192.168.49.2   80      1m
    ```

4.  **Access កម្មវិធីពីខាងក្រៅ Cluster:**
    ដោយសារយើងបានកំណត់ Hostname ផ្ទាល់ខ្លួន (`app1.example.com`, `app2.example.com`) អ្នកត្រូវកែសម្រួល File `hosts` នៅក្នុង Local Machine របស់អ្នកដើម្បី Map IP របស់ Minikube ទៅ Hostname ទាំងនេះ។

    *   **ស្វែងរក IP របស់ Minikube:**
        ```bash
        minikube ip
        ```
        ឧបមាថា IP គឺ `192.168.49.2` ។

    *   **កែសម្រួល File `hosts`:**
        *   **Linux/macOS:** បើក `/etc/hosts` ជា Administrator/root ។
        *   **Windows:** បើក `C:\Windows\System32\drivers\etc\hosts` ជា Administrator ។

        បន្ថែមបន្ទាត់ទាំងនេះនៅចុងបញ្ចប់នៃ File `hosts`:
        ```
        192.168.49.2 app1.example.com
        192.168.49.2 app2.example.com
        ```
        រក្សាទុក File ។

    *   **បើក Browser:**
        *   ចូលទៅកាន់ `http://app1.example.com` ។ អ្នកគួរតែឃើញទំព័រ `Hello NGINX!` ពី `nginxdemos/hello` Container ។
        *   ចូលទៅកាន់ `http://app2.example.com` ។ អ្នកគួរតែឃើញទំព័រ Default របស់ Nginx Container ។

### សរុបមក

Ingress គឺជា Resource ដ៏មានឥទ្ធិពលមួយសម្រាប់គ្រប់គ្រង External Access ទៅកាន់ Services របស់អ្នកនៅក្នុង Kubernetes ។ វាផ្តល់នូវភាពបត់បែនខ្ពស់ក្នុងការកំណត់ Routing Rules ដោយផ្អែកលើ Hostname ឬ Path ដែលធ្វើឱ្យវាស័ក្តិសមសម្រាប់ Production Environments ដែលមាន Microservices ជាច្រើន។ ការប្រើប្រាស់ Ingress រួមជាមួយ Ingress Controller ផ្តល់ឱ្យអ្នកនូវ Load Balancing កម្រិតខ្ពស់ និង SSL Termination ដោយមិនចាំបាច់ Provision Load Balancer ដាច់ដោយឡែកសម្រាប់គ្រប់ Service នោះទេ។

## ៤.៤ Kubernetes DNS (Service Discovery)

នៅក្នុង Kubernetes, Service Discovery គឺជាមុខងារសំខាន់មួយដែលអនុញ្ញាតឱ្យ Pods និង Services អាចស្វែងរក និងទំនាក់ទំនងគ្នាទៅវិញទៅមកដោយប្រើឈ្មោះ (DNS names) ជាជាង IP Address ដែលផ្លាស់ប្តូរជានិច្ច។ Kubernetes ផ្តល់នូវប្រព័ន្ធ DNS ផ្ទាល់ខ្លួនរបស់វា ដើម្បីសម្រួលដល់ការទំនាក់ទំនងនេះ។

### ហេតុអ្វីបានជា Kubernetes ត្រូវការ DNS?

ដូចដែលយើងបានពិភាក្សារួចមកហើយ Pods គឺ Ephemeral (បណ្ដោះអាសន្ន) ហើយ IP Address របស់ពួកវាអាចផ្លាស់ប្តូរបាននៅពេលដែល Pod ត្រូវបានលុប ឬចាប់ផ្តើមឡើងវិញ។ ប្រសិនបើកម្មវិធីត្រូវពឹងផ្អែកលើ IP Address របស់ Pod ផ្សេងទៀត នោះការទំនាក់ទំនងនឹងបែកបាក់នៅពេល IP ផ្លាស់ប្តូរ។

**Services** ដោះស្រាយបញ្ហានេះដោយផ្តល់នូវ IP Address និម្មិត (Virtual IP) និង DNS Name ថេរសម្រាប់ក្រុម Pods ។ ប្រព័ន្ធ Kubernetes DNS គឺទទួលខុសត្រូវក្នុងការបកប្រែ (resolve) DNS Name របស់ Service ទៅកាន់ Cluster IP របស់វា។

### CoreDNS

Kubernetes Clusters ភាគច្រើនប្រើ **CoreDNS** ជា DNS Server លំនាំដើមរបស់វា។ CoreDNS ដំណើរការជា Pods នៅក្នុង Namespace `kube-system` ។ រាល់ Pod ថ្មីដែលត្រូវបានបង្កើតឡើងនៅក្នុង Cluster នឹងត្រូវបានកំណត់រចនាសម្ព័ន្ធឱ្យប្រើ CoreDNS ជា DNS Server របស់វា។

### DNS Records នៅក្នុង Kubernetes

Kubernetes DNS បង្កើត DNS Records ជាច្រើនដោយស្វ័យប្រវត្តិសម្រាប់ Services និង Pods នៅក្នុង Cluster របស់អ្នក។

#### ១. Records សម្រាប់ Services

សម្រាប់ Services, Kubernetes បង្កើត DNS Records ទាំងពីរប្រភេទគឺ A record (Address record) និង SRV record (Service record)។

*   **A Record:**
    *   **ទ្រង់ទ្រាយ:** `<service-name>.<namespace-name>.svc.cluster.local`
    *   **ឧទាហរណ៍:** ប្រសិនបើអ្នកមាន Service ឈ្មោះ `my-backend-service` នៅក្នុង Namespace `production` នោះ DNS Name របស់វាគឺ `my-backend-service.production.svc.cluster.local` ។
    *   **មុខងារ:** វានឹង Resolve ទៅកាន់ **Cluster IP** របស់ Service នោះ។
    *   **Short name:** នៅក្នុង Namespace ដូចគ្នា អ្នកអាចប្រើ Short Name គឺ `my-backend-service` ។
    *   **Short name (cross-namespace):** សម្រាប់ Namespace ផ្សេងគ្នា អ្នកអាចប្រើ `my-backend-service.production` ។

*   **SRV Record (សម្រាប់ Port Discovery):**
    *   **ទ្រង់ទ្រាយ:** `_portname._protocol.<service-name>.<namespace-name>.svc.cluster.local`
    *   **ឧទាហរណ៍:** `_http._tcp.my-backend-service.production.svc.cluster.local`
    *   **មុខងារ:** វានឹង Resolve ទៅកាន់ Port និង Hostname របស់ Service ។ វាមានប្រយោជន៍សម្រាប់កម្មវិធីដែលត្រូវការស្វែងរក Port ជាក់លាក់របស់ Service ។

#### ២. Records សម្រាប់ Pods

Pods ក៏ទទួលបាន DNS Records ផងដែរ ប៉ុន្តែជាធម្មតាពួកវាត្រូវបានប្រើប្រាស់តិចជាង Records របស់ Service ។

*   **A Record (សម្រាប់ Pods):**
    *   **ទ្រង់ទ្រាយ (នៅពេល Pod មាន Service ភ្ជាប់):** `<pod-ip-address-with-hyphens>.<namespace-name>.pod.cluster.local`
    *   **ឧទាហរណ៍:** ប្រសិនបើ Pod មាន IP `10.244.1.2` នៅក្នុង Namespace `default` នោះ DNS Name របស់វាគឺ `10-244-1-2.default.pod.cluster.local` ។
    *   **ចំណាំ:** នេះមិនមែនជាវិធីដែលត្រូវបានណែនាំឱ្យ Pod ទំនាក់ទំនងគ្នាទេ។ គួរតែប្រើ Service ជា Abstraction ។

### របៀបប្រើប្រាស់ DNS នៅក្នុងកម្មវិធីរបស់អ្នក

កម្មវិធីដែលដំណើរការនៅក្នុង Pod មួយអាចស្វែងរក Service ផ្សេងទៀតបានយ៉ាងងាយស្រួលដោយប្រើ DNS Name របស់វា។

**ឧទាហរណ៍:**

ឧបមាថាអ្នកមាន Frontend Application មួយដែលដំណើរការនៅក្នុង Pod មួយ ហើយវាត្រូវការទំនាក់ទំនងជាមួយ Backend Service ឈ្មោះ `api-service` ដែលស្ថិតនៅក្នុង Namespace ដូចគ្នា។

នៅក្នុង Code របស់ Frontend Application របស់អ្នក អ្នកអាចប្រើ Hostname `api-service` ដើម្បីធ្វើ HTTP Request ទៅកាន់ Backend:

```python
import requests

# នៅក្នុង Pod មួយនៅក្នុង Namespace ដូចគ្នាជាមួយ 'api-service'
# DNS resolver នឹងបកប្រែ 'api-service' ទៅកាន់ Cluster IP របស់វា
response = requests.get("http://api-service/data")
print(response.json())
```

ប្រសិនបើ Backend Service ស្ថិតនៅក្នុង Namespace ផ្សេង (ឧទាហរណ៍ `backend-namespace`) អ្នកអាចប្រើ:

```python
# នៅក្នុង Pod មួយនៅក្នុង Namespace ផ្សេង
response = requests.get("http://api-service.backend-namespace/data")
print(response.json())
```

### ការផ្ទៀងផ្ទាត់ DNS Resolution

អ្នកអាចប្រើ `kubectl exec` ដើម្បីចូលទៅក្នុង Pod មួយហើយប្រើ Tools ដូចជា `nslookup` ឬ `dig` ដើម្បីសាកល្បង DNS Resolution ។

1.  **បង្កើត Nginx Deployment និង Service (ប្រសិនបើមិនទាន់មាន):**
    យើងនឹងប្រើ `nginx-app-deployment` និង `nginx-service` ពីផ្នែក ៤.១ ។

    ```bash
    kubectl apply -f nginx-deployment-with-labels.yaml
    kubectl apply -f nginx-service.yaml
    ```

2.  **បើក Interactive Shell នៅក្នុង Pod ណាមួយ (ឧទាហរណ៍ `nginx-app-deployment`):**
    ```bash
    kubectl exec -it <ឈ្មោះ Pod របស់ nginx-app-deployment> -- bash
    # ឧទាហរណ៍:
    # kubectl exec -it nginx-app-deployment-78f9bc687f-abcde -- bash
    ```

3.  **នៅក្នុង Shell របស់ Pod ប្រើ `nslookup`:**
    ```bash
    # សាកល្បង lookup Service នៅក្នុង Namespace ដូចគ្នា
    nslookup nginx-service

    # សាកល្បង lookup Service នៅក្នុង Namespace 'default' (full name)
    nslookup nginx-service.default.svc.cluster.local

    # សាកល្បង lookup Kubernetes API Service (វាមាននៅក្នុងគ្រប់ Cluster)
    nslookup kubernetes.default.svc.cluster.local
    ```
    អ្នកគួរតែឃើញ IP Address របស់ Service ដែលត្រូវបាន Resolve ។

### សរុបមក

Kubernetes DNS គឺជា Component ដ៏សំខាន់មួយដែលផ្តល់នូវយន្តការ Service Discovery ដ៏រឹងមាំសម្រាប់កម្មវិធីដែលដំណើរការនៅក្នុង Cluster ។ ដោយប្រើ DNS Names សម្រាប់ Services, Developers អាចបង្កើតកម្មវិធីដែលមិនអាស្រ័យលើ IP Address ជាក់លាក់របស់ Pods ដែលផ្លាស់ប្តូរជានិច្ច ដូច្នេះធានានូវភាពបត់បែន (flexibility) និងភាពងាយស្រួលក្នុងការ Scale និងគ្រប់គ្រង។

