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

## ផ្នែកទី ១៖ ការយល់ដឹងអំពី Cloud (01. Understanding Cloud)
### ១.១. និយមន័យនៃ Cloud Computing (Cloud Definition)

យោងតាម NIST (National Institute of Standards and Technology)៖
Cloud Computing គឺជាបច្ចេកវិទ្យាកុំព្យូទ័រផ្អែកលើបណ្តាញ (Network-based Computing Technology) ដែលប្រមូលផ្តុំធនធានកុំព្យូទ័រ (Computing Resources) យ៉ាងច្រើនសន្ធឹកសន្ធាប់ទៅក្នុងមជ្ឈមណ្ឌលទិន្នន័យ (Data Center) រួចធ្វើការបែងចែកធនធានទាំងនោះជាលក្ខណៈនិម្មិត (Virtually Separated) ទៅតាមតម្រូវការជាក់ស្តែងរបស់អ្នកប្រើប្រាស់ម្នាក់ៗ និងផ្តល់សេវាជូនតាមរយៈបណ្តាញព័ត៌មានវិទ្យា (Internet/Network)។

### ១.២. លក្ខណៈពិសេសគ្រឹះទាំង ៥ នៃ Cloud (Basic Properties / Cloud Features)
យោងតាមស្តង់ដារ NIST បច្ចេកវិទ្យា Cloud មានលក្ខណៈសម្បត្តិសំខាន់ៗចំនួន ៥៖

1. **On-Demand Self-Service (សេវាកម្មស្វ័យប្រវត្តិ តាមតម្រូវការ)៖** អ្នកប្រើប្រាស់អាចស្នើសុំ និងរៀបចំរចនាសម្ព័ន្ធធនធាន (ដូចជា Server, Storage) ដោយខ្លួនឯងតាមរយៈផ្ទាំងគ្រប់គ្រង (Management Screen/Portal) ដោយមិនចាំបាច់មានការទាក់ទង ឬអន្តរាគមន៍ផ្ទាល់ពីអ្នកប្រតិបត្តិការប្រព័ន្ធ (Operator) ឡើយ។

2. **Broad Network Access / Extensive Network Connectivity (ការចូលប្រើប្រាស់តាមបណ្តាញទូលំទូលាយ)៖** សេវាកម្ម Cloud អាចចូលប្រើប្រាស់បានតាមរយៈបណ្តាញអ៊ីនធឺណិត ដោយប្រើប្រាស់ឧបករណ៍ចម្រុះដូចជា Mobile Devices, Laptops, Desktops, និង Tablets។

3. **Resource Pooling / Resource Sharing (ការចែករំលែកធនធាន)៖** ធនធានកុំព្យូទ័ររបស់អ្នកផ្តល់សេវា (Cloud Provider) ត្រូវបានដាក់បញ្ចូលគ្នាក្នុងអាងធនធាន (Resource Pool) ដើម្បីចែករំលែកប្រើប្រាស់ដោយអ្នកប្រើប្រាស់ច្រើននាក់ (Multi-Tenant) ដោយបែងចែកតាមកម្រិតនិម្មិត (Virtual Level)។

4. **Rapid Elasticity / Expedite Scalability (ភាពបត់បែន និងការពង្រីកធនធានបានរហ័ស)៖** ធនធានអាចពង្រីក (Scale up/out) ឬបង្រួម (Scale down/in) បានយ៉ាងរហ័សទៅតាមតម្រូវការជាក់ស្តែងនៃការប្រែប្រួលទិន្នន័យ និងបន្ទុកការងារ (Workload)។

5. **Measured Service (សេវាកម្មដែលមានការវាស់វែង / Pay-as-you-go)៖** ប្រព័ន្ធ Cloud មានប្រព័ន្ធវាស់វែង និងត្រួតពិនិត្យការប្រើប្រាស់ធនធានយ៉ាងច្បាស់លាស់ (Resource Monitoring & Billing) ដែលអនុញ្ញាតឱ្យគិតថ្លៃសេវាទៅតាមចំនួន និងរយៈពេលដែលបានប្រើប្រាស់ជាក់ស្តែង (Pay-as-you-go system)។

### ១.៣. អត្ថប្រយោជន៍នៃការប្រើប្រាស់ Cloud (Cloud Usability)
- Economics (សេដ្ឋកិច្ច និងការសន្សំសំចៃ)៖ ការគ្រប់គ្រង Software និង Data ជារួមនៅលើ Cloud ជួយបង្កើនប្រសិទ្ធភាពនៃការអាប់ដេត Software និងការថែទាំ Data ដែលកាត់បន្ថយចំណាយប្រតិបត្តិការផ្ទាល់។

- Flexibility (ភាពបត់បែន)៖ ការប្រើប្រាស់ធនធានកុំព្យូទ័របត់បែនតាមតម្រូវការ – អាចពង្រីកនៅពេលត្រូវការ និងបង្រួមនៅពេលឈប់ត្រូវការ។

- Availability (ភាពអាចប្រើប្រាស់បានខ្ពស់ - High Availability)៖ ប្រព័ន្ធត្រូវ បានរចនាឡើងដើម្បីធានាថា សេវាកម្មនៅតែអាចដំណើរការបាន ទោះបីជាមានការខូចខាត Hardware មួយចំនួនក៏ដោយ។ ដំណើរការបរិស្ថាន High Availability នៅលើ Cloud មានតម្លៃធូរថ្លៃជាងការបង្កើត On-premise System ផ្ទាល់ខ្លួន។

- Fast Deployment (ការដាក់ឱ្យដំណើរការបានរហ័ស)៖ អាចបង្កើត និងដាក់ប្រព័ន្ធឱ្យដំណើរការយ៉ាងឆាប់រហ័ស ដោយប្រើប្រាស់ Hardware និង Software ដែលមានស្រាប់នៅលើ Cloud។

### ១.៤. ប្រវត្តិ និងដំណើរវិវត្តនៃ Cloud (Cloud History & Evolution)
- **First Generation Cloud (ជំនាន់ទី ១)៖** ការបង្កើតទីផ្សារ Cloud ទ្រង់ទ្រាយធំដំបូងគេ ដែលផ្តោតលើ Centralized Cloud ដោយផ្អែកលើ Data Center។

- **Second Generation Cloud (ជំនាន់ទី ២)៖** ការកើនឡើងយ៉ាងរហ័សនៃឧស្សាហកម្ម Cloud, ការលេចធ្លោនៃ DevOps (Development & Operations), ការប្រើប្រាស់ Microservices ក្នុងការអភិវឌ្ឍ Cloud Applications, ការប្រើប្រាស់ Container Technology (ដូចជា Docker, Kubernetes - CNCF), OpenStack, និងការរួមបញ្ចូល Public + Private ទៅជា Hybrid Cloud។

- **Next Generation Cloud (ជំនាន់បន្ត)៖** ការលេចឡើងនៃ Edge Computing ដើម្បីកាត់បន្ថយភាពយឺតយ៉ាវ (Latency) ពី Centralized Cloud, ការរួមបញ្ចូលជាមួយ IoT (Internet of Things) រាប់ពាន់លានឧបករណ៍, ការរីកចម្រើននៃ 5G Network, និងការអនុវត្ត AI/ML។

### ១.៥. និន្នាការនៃ Cloud Computing (Cloud Computing Trends)
1. **Increased Investment in Cloud Security and Resiliency៖** ការវិនិយោគលើសុវត្ថិភាព Cloud និងភាពធន់នៃប្រព័ន្ធ ដើម្បីប្រឈមមុខនឹងការគំរាមកំហែង Cybersecurity តាមរយៈ AI និង Security-as-a-Service។

2. **Growing Demand for Multi-Cloud៖** ការកើនឡើងនៃតម្រូវការប្រើប្រាស់ Multi-Cloud ដើម្បីកាត់បន្ថយហានិភ័យនៃ Vendor Lock-in លើ Cloud Provider តែមួយ។

3. **AI and Machine Learning (ML)-based Cloud៖** ការប្រើប្រាស់ Cloud Infrastructure ដើម្បីបណ្តុះបណ្តាល និងដំណើរការម៉ូដែល AI/ML ធំៗ។

4. **Low-Code and No-Code Cloud Services៖** បច្ចេកវិទ្យាដែលអនុញ្ញាតឱ្យបង្កើត Application ដោយមិនបាច់សរសេរកូដច្រើន ឬមិនបាច់សរសេរកូដសោះ។

5. **Innovation in Cloud-Based Gaming៖** ការប្រែប្រួលនៃការលេងហ្គេមតាមរយៈ Streaming Video Games (Cloud Gaming) ដោយសារការមកដល់នៃបណ្តាញ 5G។

## ផ្នែកទី ២៖ ការយល់ដឹងអំពី Cloud Models និង លក្ខណៈពិសេស (02. Understanding Cloud Models and Features)

### ២.១. ប្រភេទនៃ Cloud តាមទម្រង់ប្រតិបត្តិការ (Cloud Deployment Models)
1. **Public Cloud (ក្លោដសាធារណៈ)៖** ជាប្រភេទ Cloud ដែលប្រើប្រាស់ធនធាន និងសេវាកម្មផ្តល់ដោយក្រុមហ៊ុនខាងក្រៅ (Cloud Service Provider - CSP ដូចជា AWS, Azure, GCP)។ វាផ្តល់អត្ថប្រយោជន៍អតិបរមានៃភាពបត់បែន និងការសន្សំសំចៃចំណាយ។

2. **Private Cloud (ក្លោដឯកជន)៖** ជាប្រភេទ Cloud ដែលក្រុមហ៊ុន ឬស្ថាប័នបង្កើត និងប្រើប្រាស់ផ្ទៃក្នុង (Internal Use) ដោយផ្តល់សេវាកម្មក្នុងកម្រិតកំណត់ តែមានសុវត្ថិភាពខ្ពស់ និងអាចកែច្នៃតាមតម្រូវការផ្ទាល់ខ្លួន (Customization)។
3. **Hybrid Cloud (ក្លោដចម្រុះ)៖** ជាការបូកបញ្ចូលគ្នារវាង Private Cloud (ផ្តោតលើសុវត្ថិភាពទិន្នន័យ) និង Public Cloud (ផ្តោតលើការកាត់បន្ថយចំណាយ និងភាពបត់បែន)។

4. **Multi-Cloud (ក្លោដច្រើនប្រភេទ)៖** ជាទម្រង់ដែលក្រុមហ៊ុន ឬស្ថាប័នប្រើប្រាស់ Public Cloud ច្រើនជាងមួយក្នុងពេលតែមួយ (ឧ. AWS + Azure + GCP) ដើម្បីជ្រើសរើសសេវាកម្មដែលល្អបំផុតតាមតម្រូវការ។

5. **Public-Private-Partnership (PPP) Cloud / Distributed Cloud៖** ការនាំយកប្រព័ន្ធ Public Cloud មកដំឡើង និងប្រតិបត្តិការនៅខាងក្នុងស្ថាប័ន ដើម្បីទទួលបានទាំងស្ថេរភាពរបស់ Public Cloud និងសុវត្ថិភាពរបស់ Private Cloud។

6. **Edge Cloud (ក្លោដក្បែរអ្នកប្រើប្រាស់)៖** ការបែងចែក Cloud ជា Main Cloud និង Edge Cloud ដោយដាក់ Edge Cloud នៅជិតទីតាំងដែលបង្កើតទិន្នន័យ (ដូចជា IoT Sensors, Autonomous Vehicles) ដើម្បីប្រមូល និងចាត់ចែងទិន្នន័យបានលឿនបំផុត (Low Latency) រួចផ្ញើតែទិន្នន័យសំខាន់ៗទៅកាន់ Main Cloud។

### ២.២. ប្រភេទនៃ Cloud តាមទម្រង់សេវាកម្ម (Cloud Service Models)
#### ក. IaaS (Infrastructure as a Service)

- **និយមន័យ៖** ជាម៉ូឌែលដែលផ្តល់ធនធានកុំព្យូទ័រគ្រឹះ (Computing Resources) ដូចជា CPU, Memory, Storage, និង Network ក្នុងទម្រង់ជាសេវាកម្មតាមបណ្តាញ។
- **លក្ខណៈពិសេស៖** ការធ្វើ Virtualization លើ Physical Resources ដើម្បីផ្តល់នូវ Infrastructure ដែលបត់បែន។
- **ប្រភេទនៃ Virtualization ក្នុង IaaS៖**
  - **Hypervisor-based Virtualization (VM-based)៖** ដំណើរការ Guest OS ដាច់ដោយឡែកនៅលើ Hypervisor (ឧ. Bare-metal/Native: Xen, Hyper-V, KVM; Host-based: VMware)។ មានសុវត្ថិភាពខ្ពស់ (Isolated at OS level) តែប្រើប្រាស់ Resource ច្រើន និងចំណាយពេល Start យូរជាង (ជា minute)។
  - **Container Virtualization (Container-based)៖** ដំណើរការ Execution Environment ច្រើននៅលើ Host OS តែមួយ ដោយប្រើ Container Management Software (ឧ. Docker, Kubernetes)។ ប្រើប្រាស់ Resource តិច, Start លឿន (ជា second), ប៉ុន្តែសាកសមសម្រាប់ការបែងចែកកម្រិត Process Level។
#### ខ. PaaS (Platform as a Service)
- **និយមន័យ៖** ជាម៉ូឌែលដែលផ្តល់នូវបរិស្ថានអភិវឌ្ឍន៍ និងដំណើរការកម្មវិធី (Application Execution and Development Environment) ក្នុងទម្រង់ជាសេវាកម្ម។
- **អត្ថប្រយោជន៍៖**
  - អ្នកអភិវឌ្ឍន៍ (Developers) មិនចាំបាច់រៀបចំ Hardware, OS, ឬ Middleware ដោយខ្លួនឯងឡើយ ដោយផ្តោតតែលើការសរសេរកូដ (Development) ប៉ុណ្ណោះ។
  - សម្រួលដល់ការអនុវត្តវប្បធម៌ DevOps (Development & Operations) និងកាត់បន្ថយពេលវេលានៃ S/W Lifecycle (ពីអភិវឌ្ឍន៍រហូតដល់ Deployment)។
- **សមាសភាគសំខាន់ៗក្នុង PaaS៖**
  - Build Pack៖ ការគាំទ្របច្ចេកទេស និងភាសាសរសេរកូដ (Language Frameworks) ដូចជា Java (Spring/Grails), Node.js, Python (Django/Flask), Go, .NET Core, PHP, Ruby, R ជាដើម។
  - Service Pack / Marketplace Services៖ សេវាកម្មបន្ថែមដែលមានស្រាប់សម្រាប់ភ្ជាប់ប្រើប្រាស់ ដូចជា Database (MySQL, MongoDB, Redis, CUBRID), Messaging (RabbitMQ), Storage (GlusterFS), APM Monitoring (Pinpoint), និង CI/CD Delivery Pipeline។
#### គ. SaaS (Software as a Service)**
- **និយមន័យ៖** ជាម៉ូឌែលដែលផ្តល់មុខងាររបស់ Software ទាំងមូលជាសេវាកម្មតាមរយៈបណ្តាញ Internet (ជួនកាលហៅថា "On-Demand SW")។ អ្នកប្រើប្រាស់មិនបាច់ដំឡើង Program ទេ គឺចូលប្រើប្រាស់តាម Web Browser និងបង់ថ្លៃតាមការប្រើប្រាស់។
- **លក្ខណៈបច្ចេកទេសសំខាន់ៗ៖**
  1. Configuration (ការកំណត់តាមការតម្រូវ)៖ អាចកំណត់ប្រព័ន្ធតាមតម្រូវការអ្នកប្រើប្រាស់បានដោយមិនបាច់កែកូដ (Source Code) ឡើយ។
  2. Multi-Tenancy (ការចែករំលែកប្រើប្រាស់ច្រើនអ្នក)៖ រចនាសម្ព័ន្ធ Multi-Tenant អនុញ្ញាតឱ្យអ្នកប្រើប្រាស់ច្រើននាក់ (Tenants) ប្រើប្រាស់សូហ្វវែរ ឬ Instance តែមួយ ប៉ុន្តែទិន្នន័យ និងបរិស្ថានរបស់ Tenant នីមួយៗត្រូវ បានបំបែកដាច់ដោយឡែកពីគ្នា (Isolated Environment)។
  3. Scalability (សមត្ថភាពពង្រីក)៖ អាចបង្កើត Instance បន្ថែមដើម្បីគាំទ្របន្ទុកការងាររហ័ស។
- **កម្រិតភាពចាស់ទុំនៃ SaaS (SaaS Maturity Levels)៖**
  - Level 1 (ASP-like)៖ មាន Application Instance ដាច់ដោយឡែកសម្រាប់អតិថិជនម្នាក់ៗ។
  - Level 2 (Customizable via Settings)៖ មាន Application Instance ដាច់ដោយឡែក ប៉ុន្តែអាច Configure តាមសេចក្តីត្រូវការរបស់អតិថិជននីមួយៗ។
  - Level 3 (Multi-Tenant, Single Instance)៖ អតិថិជនទាំងអស់ប្រើប្រាស់ Instance តែមួយរួមគ្នា ដោយបែងចែកតាម Metadata ( Resource Management មានប្រសិទ្ធភាពខ្ពស់)។
  - Level 4 (Multi-Tenant, Scalable Load-Balanced)៖ ម៉ូឌែលចាស់ទុំបំផុត ដែលដំណើរការលើប្រព័ន្ធ Load-Balancing មាន Multiple Instances និងការបែងចែកទិន្នន័យអតិថិជនបែប Distributed Management។
### ២.៣. ការប្រៀបធៀប Cloud Service Models (IaaS vs CaaS vs PaaS vs FaaS vs SaaS)
| ម៉ូឌែល Cloud | កម្រិតនៃការគ្រប់គ្រង (Scope of Management) | អ្នកប្រើប្រាស់គោលដៅ (Target User) | ឧទាហរណ៍សមាសភាគ/សេវា| 
|---|---|---|---|
Iaa | SVirtual Machines, Disk, Network, Firewall | System / IT Administrators | AWS EC2, GCP Compute Engine, Azure VM | 
| CaaS | Containers, Volume, IP & Port, Load Balancer | DevOps / Infrastructure Engineers | Kubernetes, Amazon ECS/EKS, Docker Swarm | 
| PaaS / aPaaS | Web/WAS, Framework, App, Route | Developers / Application Engineers | Google App Engine, AWS Elastic Beanstalk, Cloud Foundry |
| FaaS (Serverless) | Action, Trigger, Gateway, API, Code | Developers | AWS Lambda, Google Cloud Functions |
| SaaS | Complete End-to-End Application & Service | End Users / Business Users | Office 365, Google Workspace, Salesforce

- **Low Level Abstraction (IaaS/CaaS)៖** ផ្តល់ភាពបត់បែនខ្ពស់ (High Flexibility) ប៉ុន្តែត្រូវការការគ្រប់គ្រងច្រើន។
- **High Level Abstraction (FaaS/SaaS)៖** ផ្តល់ល្បឿនក្នុងការអភិវឌ្ឍ និងដាក់ឱ្យដំណើរការលឿន (High Velocity) ដោយអ្នកប្រើប្រាស់គ្រាន់តែបង់ថ្លៃសេវា និងប្រើប្រាស់មុខងារភ្លាមៗ។