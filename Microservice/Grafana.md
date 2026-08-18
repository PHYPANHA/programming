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

# មាតិកាមេរៀនលម្អិត៖ ការប្រើប្រាស់ Grafana សម្រាប់ Monitoring & Observability ក្នុងប្រព័ន្ធ Microservices

**ជំពូកទី ១៖ សេចក្តីផ្តើមអំពី Observability ក្នុង Microservices**
* ១.១ តើអ្វីទៅជា Observability? (Observability vs Monitoring)
* ១.២ បញ្ហាប្រឈមនៃ Monitoring ក្នុងស្ថាបត្យកម្ម Microservices
* ១.៣ សសរស្តម្ភទាំង ៣ នៃ Observability (The Three Pillars): Metrics, Logs, និង Traces
* ១.៤ ហេតុអ្វីត្រូវជ្រើសរើស Grafana Stack?

**ជំពូកទី ២៖ ការស្គាល់ Grafana Ecosystem (LGTM Stack)**
* ២.១ ការស្វែងយល់ពី Grafana: The Visualization Layer
* ២.២ Prometheus: ការផ្ទុក Metrics និងការប្រើប្រាស់ Pull-based Model
* ២.៣ Grafana Loki: ការគ្រប់គ្រង Logs បែប Cloud-native
* ២.៤ Grafana Tempo: ដំណោះស្រាយសម្រាប់ Distributed Tracing
* ២.៥ ទំនាក់ទំនងរវាង Component នីមួយៗ

**ជំពូកទី ៣៖ ការរៀបចំ Environment ជាក់ស្តែងជាមួយ Docker Compose**
* ៣.១ ការតំឡើង Docker និង Docker Compose
* ៣.២ ការសរសេរឯកសារ `docker-compose.yaml` សម្រាប់ Grafana Stack
* ៣.៣ ការរៀបចំ Network និង Storage សម្រាប់ Persistence Data
* ៣.៤ ការផ្ទៀងផ្ទាត់ដំណើរការនៃសេវាកម្មនីមួយៗ

**ជំពូកទី ៤៖ ការប្រមូល និងវិភាគ Metrics ជាមួយ Prometheus + Exporters**
* ៤.១ ស្វែងយល់ពី Prometheus Architecture (Scrape configs, Targets)
* ៤.២ ការប្រើប្រាស់ Node Exporter សម្រាប់តាមដាន Server Resources (CPU, RAM, Disk)
* ៤.៣ ការប្រើប្រាស់ cAdvisor សម្រាប់តាមដាន Docker Containers
* ៤.៤ មូលដ្ឋានគ្រឹះនៃភាសា PromQL (Prometheus Query Language)

**ជំពូកទី ៥៖ ការគ្រប់គ្រង Logs រួមគ្នាជាមួយ Loki និង Promtail**
* ៥.១ Architecture របស់ Loki: ហេតុអ្វីវាលឿន និងចំណាយតិច?
* ៥.២ ការប្រើប្រាស់ Promtail ដើម្បី Scrape logs ពី Containers
* ៥.៣ ការប្រើប្រាស់ LogQL ដើម្បីស្វែងរក និង Filter ទិន្នន័យ Logs
* ៥.៤ ការតភ្ជាប់ Logs ទៅកាន់ Metrics (Extracting metrics from logs)

**ជំពូកទី ៦៖ ការធ្វើ Distributed Tracing ជាមួយ Tempo**
* ៦.១ តើអ្វីទៅជា Distributed Tracing និង Span?
* ៦.២ ការយល់ដឹងពី Trace ID និង Span ID
* ៦.៣ ការបញ្ចូល Instrumentation ក្នុង Microservices (OpenTelemetry basics)
* ៦.៤ ការវិភាគ Request Flow តាមរយៈ Tempo Dashboard

**ជំពូកទី ៧៖ ការបង្កើត Dashboards ប្រកបដោយវិជ្ជាជីវៈ (Best Practices)**
* ៧.១ ការរចនា Dashboard តាមគោលការណ៍ "Golden Signals" (Latency, Traffic, Errors, Saturation)
* ៧.២ ការប្រើប្រាស់ Variables ក្នុង Grafana សម្រាប់ Dynamic Dashboards
* ៧.៣ ការបង្កើត Visualization ប្រភេទផ្សេងៗ (Time series, Bar gauge, Stat, Table)
* ៧.៤ បច្ចេកទេសរៀបចំ Row និង Panel ឱ្យមានរបៀបរៀបរយ

**ជំពូកទី ៨៖ ការរៀបចំ Alerting System**
* ៨.១ ការបង្កើត Alert Rules ក្នុង Grafana និង Prometheus
* ៨.២ ការគ្រប់គ្រង Notification Policies និង Silences
* ៨.៣ ការភ្ជាប់ Contact Points ជាមួយ Telegram និង Slack
* ៨.៤ ការសរសេរ Alert Template ឱ្យមានព័ត៌មានគ្រប់គ្រាន់សម្រាប់ SRE Team

**ជំពូកទី ៩៖ ការអនុវត្តផ្ទាល់ (Mini-Project)**
* ៩.១ ការដាក់បញ្ជូល Grafana Stack ទៅក្នុង Java/Node.js/Go Microservices គំរូ
* ៩.២ ការបង្កើត Full Observability Dashboard (Combined Metrics, Logs, Traces)
* ៩.៣ ការធ្វើតេស្តសាកល្បងបង្កើត Error ដើម្បីឱ្យ Alert ដំណើរការ
* ៩.៤ សេចក្តីសន្និដ្ឋាន និងការណែនាំសម្រាប់ជំហានបន្ទាប់

# ជំពូកទី ១៖ សេចក្តីផ្តើមអំពី Observability ក្នុង Microservices

នៅក្នុងពិភពនៃ **Microservices** ដែលមានសេវាកម្មរាប់សិប ឬរាប់រយដំណើរការជាមួយគ្នា ការយល់ដឹងពីអ្វីដែលកំពុងកើតឡើងនៅខាងក្នុងប្រព័ន្ធគឺជារឿងចាំបាច់បំផុត។

### ១.១ តើអ្វីទៅជា Observability? (Observability vs Monitoring)

ជារឿយៗ មនុស្សភាគច្រើនច្រឡំរវាងពាក្យទាំងពីរនេះ៖

*   **Monitoring (ការតាមដាន):** គឺជាដំណើរការនៃការប្រមូលទិន្នន័យដើម្បីប្រាប់យើងថា **"តើប្រព័ន្ធកំពុងដំណើរការ ឬអត់?"** (Is the system working?). វាផ្តោតទៅលើការដឹងពីបញ្ហាដែលយើងធ្លាប់ជួបពីមុន (Known-unknowns) ដូចជា CPU ឡើងខ្ពស់ ឬ Disk ពេញជាដើម។
*   **Observability (សមត្ថភាពសង្កេត):** គឺជាសមត្ថភាពដែលអនុញ្ញាតឱ្យយើងយល់ពីស្ថានភាពខាងក្នុងនៃប្រព័ន្ធ ដោយផ្អែកលើទិន្នន័យដែលវាបញ្ចេញមកខាងក្រៅ (External outputs)។ វាជួយយើងឆ្លើយសំណួរថា **"ហេតុអ្វីបានជាវាហុចលទ្ធផលបែបនេះ?"** (Why is it happening?). វាផ្តោតលើការរកឃើញបញ្ហាដែលយើងមិនធ្លាប់ស្មានដល់ (Unknown-unknowns)។

> **សេចក្តីសន្និដ្ឋាន:** Monitoring ប្រាប់អ្នកថាមានភ្លើងឆេះ ចំណែក Observability ជួយអ្នករកឃើញថា តើភ្លើងនោះចាប់ផ្តើមឆេះចេញពីកន្លែងណា និងដោយសារមូលហេតុអ្វី។

### ១.២ បញ្ហាប្រឈមនៃ Monitoring ក្នុងស្ថាបត្យកម្ម Microservices

នៅពេលយើងប្តូរពី Monolith (កម្មវិធីតែមួយដុំធំ) ទៅជា Microservices យើងជួបបញ្ហាដូចជា៖
1.  **Distributed Complexity:** Request មួយអាចឆ្លងកាត់សេវាកម្មរាប់សិប។ បើមាន Error កើតឡើង យើងពិបាករកណាស់ថាវាខូចនៅសេវាកម្មមួយណា។
2.  **Ephemeral Infrastructure:** Container អាចកើត និងរលត់គ្រប់ពេល ធ្វើឱ្យការតាមដានតាមរយៈ Static IP លែងមានប្រសិទ្ធភាព។
3.  **Data Silos:** Logs របស់សេវាកម្មនីមួយៗនៅដាច់ដោយឡែកពីគ្នា ធ្វើឱ្យការវិភាគរួម (Correlation) មានការលំបាក។

### ១.៣ សសរស្តម្ភទាំង ៣ នៃ Observability (The Three Pillars)

ដើម្បីសម្រេចបាននូវ Full Observability យើងត្រូវការធាតុផ្សំ ៣ យ៉ាង៖

1.  **Metrics (រង្វាស់រង្វាល់):**
    *   ជាទិន្នន័យលេខ (Numeric data) ដែលប្រមូលបានតាមកាលកំណត់ (Time-series)។
    *   ឧទាហរណ៍៖ ចំនួន Request ក្នុង ១ វិនាទី, ភាគរយនៃកំហុស (Error Rate), ការប្រើប្រាស់ Memory។
    *   *ឧបករណ៍:* **Prometheus**

2.  **Logs (កំណត់ត្រាព្រឹត្តិការណ៍):**
    *   ជាអត្ថបទ (Text data) ដែលបញ្ជាក់ពីអ្វីដែលបានកើតឡើងនៅពេលជាក់លាក់ណាមួយ។
    *   ឧទាហរណ៍៖ `User 'admin' failed to login at 10:00 AM due to wrong password`។
    *   *ឧបករណ៍:* **Grafana Loki**

3.  **Traces (ការតាមដានខ្សែសង្វាក់):**
    *   បង្ហាញពីដំណើរនៃ Request មួយ ចាប់ពីពេលវាចូលមកដល់ប្រព័ន្ធ រហូតដល់វាចេញទៅវិញ (End-to-end flow)។
    *   វាបង្ហាញពី Latency (ភាពយឺត) នៃសេវាកម្មនីមួយៗដែល Request នោះឆ្លងកាត់។
    *   *ឧបករណ៍:* **Grafana Tempo**

### ១.៤ ហេតុអ្វីត្រូវជ្រើសរើស Grafana Stack?

Grafana មិនមែនត្រឹមតែជាកន្លែងមើល Dashboard នោះទេ ប៉ុន្តែវាគឺជា **Observability Platform** ដែលអាច៖
*   **Unified View:** មើល Metrics, Logs, និង Traces ក្នុងកន្លែងតែមួយ។
*   **Correlation:** ចុចលើ Metrics ហើយលោតទៅមើល Logs ដែលពាក់ព័ន្ធភ្លាមៗ (Log-to-metric linkage)។
*   **Open Source:** មានសហគមន៍គាំទ្រច្រើន និងអាចតំឡើងលើ Infrastructure ខ្លួនឯងបាន (Self-hosted)។

| **ឧទាហរណ៍** | CPU > 90%, វេបសាយចូលមិនកើត | សេវាកម្ម A យឺតដោយសារ database ជាប់ lock |

#### ឧទាហរណ៍ជាក់ស្តែងតាមរយៈការបើកបររថយន្ត៖

*   **Monitoring:** គឺដូចជា **កុងទ័រឡាន (Dashboard)**។ វាប្រាប់អ្នកពីល្បឿន, កម្រិតសាំង និងសីតុណ្ហភាពម៉ាស៊ីន។ បើសាំងអស់ វានឹងលោតភ្លើងសញ្ញាប្រាប់អ្នក (Alert)។ ប៉ុន្តែវាមិនអាចប្រាប់អ្នកបានទេថា ហេតុអ្វីបានជាសាំងឆាប់អស់ខុសធម្មតា?
*   **Observability:** គឺដូចជាការមាន **ប្រព័ន្ធ Computer ពិនិត្យម៉ាស៊ីន (Diagnostic Tool)**។ នៅពេលឡានមានបញ្ហា អ្នកអាចដោតម៉ាស៊ីននោះដើម្បីមើលទិន្នន័យលម្អិតពីគ្រប់ផ្នែកទាំងអស់ ដើម្បីដឹងថា តើមកពីប៊ិចសាំងស្ទះ ឬមកពីប្រព័ន្ធភ្លើងដំណើរការមិនស្របគ្នា ទើបបណ្តាលឱ្យសាំងឆាប់អស់។

#### ហេតុអ្វីបានជា Microservices ត្រូវការ Observability ខ្លាំងជាង Monolith?
ក្នុងប្រព័ន្ធ Monolith កូដទាំងអស់នៅជុំគ្នា ការ Debug គឺងាយស្រួល។ ប៉ុន្តែក្នុង Microservices៖
1.  **Dependencies:** សេវាកម្មមួយអាចប៉ះពាល់ដល់សេវាកម្មដប់ទៀត។
2.  **Concurrency:** មានរឿងរាប់ពាន់កើតឡើងក្នុងពេលតែមួយ។
3.  **Blind Spots:** ការមានត្រឹមតែ Monitoring នឹងធ្វើឱ្យអ្នកមាន "ចំណុចងងឹត" ច្រើន ដែលមិនអាចមើលឃើញពីទំនាក់ទំនងរវាងសេវាកម្មនីមួយៗបាន។

# ជំពូកទី ២៖ ការស្គាល់ Grafana Ecosystem (LGTM Stack)

ដើម្បីកសាងប្រព័ន្ធ Observability ពេញលេញ Grafana Labs បានបង្កើតនូវអ្វីដែលគេហៅថា **LGTM Stack** (Loki, Grafana, Tempo, Mimir/Prometheus)។ ឧបករណ៍ទាំងនេះធ្វើការជាមួយគ្នាដើម្បីផ្តល់រូបភាពច្បាស់លាស់នៃ Microservices របស់អ្នក។

### ២.១ ការស្វែងយល់ពី Grafana: The Visualization Layer

Grafana គឺជាបេះដូងនៃ Stack នេះ។ វាគឺជា **Open-source Visualization និង Analytics platform** ដែលពេញនិយមបំផុតក្នុងលោក។

*   **តួនាទី:** វាមិនមែនជាអ្នកផ្ទុកទិន្នន័យ (Database) ទេ ប៉ុន្តែវាជាអ្នកតភ្ជាប់ទៅកាន់ Data Sources (ដូចជា Prometheus, Loki) ដើម្បីទាញយកទិន្នន័យមកបង្ហាញជាក្រាហ្វ (Graphs), តារាង (Tables) ឬ Map។
*   **លក្ខណៈពិសេស:** វាអនុញ្ញាតឱ្យយើងបង្កើត Dashboard ដែលមានភាពរស់រវើក, ការប្រើប្រាស់ Variables ដើម្បីធ្វើ Dynamic Views និងការកំណត់ Alert Rules រួមគ្នាក្នុងកន្លែងតែមួយ។

### ២.២ Prometheus & Grafana Mimir: ការគ្រប់គ្រង Metrics

*   **Prometheus:** គឺជាឧបករណ៍ស្តង់ដារសម្រាប់ប្រមូល និងរក្សាទុកទិន្នន័យប្រភេទ **Time-series Metrics**។ វាប្រើប្រាស់វិធីសាស្ត្រ **Pull Model** (វាទៅទាញទិន្នន័យពីសេវាកម្មដោយខ្លួនឯង) និងមានភាសា Query ផ្ទាល់ខ្លួនហៅថា PromQL។
*   **Grafana Mimir:** បើសិនជាអ្នកមានទិន្នន័យ Metrics ច្រើនខ្លាំង (Scale ធំ) Mimir ត្រូវបានប្រើដើម្បីពង្រីកសមត្ថភាព Prometheus។ វាអនុញ្ញាតឱ្យអ្នកផ្ទុក Metrics បានរាប់លាន (Horizontally Scalable) និងរក្សាទុកបានយូរអង្វែង (Long-term storage) ដោយប្រើប្រាស់ Object Storage ដូចជា S3។

### ២.៣ Grafana Loki: ការគ្រប់គ្រង Logs បែប Cloud-native

Loki ត្រូវបានគេហៅថា "Prometheus for Logs" ព្រោះវាប្រើប្រាស់ Concept ដូចគ្នាទៅនឹង Prometheus។

*   **ហេតុអ្វីបានជាពិសេស?** ខុសពី ELK Stack (Elasticsearch) ដែលធ្វើ Index លើរាល់ពាក្យក្នុង Log ធ្វើឱ្យវាស៊ី Resource ខ្លាំង, Loki ធ្វើ Index តែលើ **Labels** (Metadata ដូចជា `app=auth`, `env=production`) ប៉ុណ្ណោះ។
*   **អត្ថប្រយោជន៍:** វាចំណាយ Storage តិចខ្លាំង និងមានល្បឿនលឿនក្នុងការទាញយក Logs មកមើលតាមរយៈ Label selection និងប្រើប្រាស់ភាសា LogQL។

### ២.៤ Grafana Tempo: ដំណោះស្រាយសម្រាប់ Distributed Tracing

នៅពេល Request មួយឆ្លងកាត់សេវាកម្ម A, B, C... រហូតដល់ D យើងត្រូវការ Tempo ដើម្បីមើលផ្លូវដើររបស់វា។

*   **តួនាទី:** វាផ្ទុកទិន្នន័យ **Traces** ដែលជួយឱ្យយើងឃើញ Sequence នៃ Request និងរយៈពេល (Latency) ដែលសេវាកម្មនីមួយៗប្រើប្រាស់។
*   **Seamless Correlation:** Tempo ត្រូវបានរចនាឡើងឱ្យស៊ីគ្នាជាមួយ Loki និង Prometheus។ អ្នកអាចមើល Metrics ឃើញ Error រួចចុចមើល Logs ហើយលោតទៅមើល Trace ក្នុង Tempo បានភ្លាមៗដោយប្រើ `trace_id`។

### ២.៥ ទំនាក់ទំនងរវាង Component នីមួយៗ (The Power of Correlation)

រូបមន្តនៃភាពជោគជ័យរបស់ Grafana Ecosystem មិនមែននៅត្រង់ឧបករណ៍នីមួយៗខ្លាំងនោះទេ ប៉ុន្តែនៅត្រង់ **សមត្ថភាពតភ្ជាប់ទិន្នន័យ (Correlation)**៖

1.  **Metrics (Prometheus):** ប្រាប់ថា "មានបញ្ហា!" (ឧទាហរណ៍៖ អត្រា Error កើនឡើងដល់ ៥%)។
2.  **Logs (Loki):** ប្រាប់ថា "តើវាជាបញ្ហាអ្វី?" (ឧទាហរណ៍៖ ការមើល Error Message ក្នុង Logs ឃើញថា `Database Connection Timeout`)។
3.  **Traces (Tempo):** ប្រាប់ថា "តើបញ្ហានោះកើតឡើងនៅត្រង់ណា?" (ឧទាហរណ៍៖ Request យឺតនៅត្រង់សេវាកម្មបង់ប្រាក់ មិនមែននៅសេវាកម្មកម្មង់ទំនិញទេ)។

| ឧបករណ៍ | ប្រភេទដាទ៌ (Data Type) | គោលបំណងចម្បង | ភាសា Query |
| :--- | :--- | :--- | :--- |
| **Prometheus** | **Metrics** (Numbers) | ការវាស់វែងបរិមាណ និងស្ថានភាព | PromQL |
| **Loki** | **Logs** (Text) | ការពិនិត្យមើលព្រឹត្តិការណ៍លម្អិត | LogQL |
| **Tempo** | **Traces** (Request Flow) | ការមើលខ្សែសង្វាក់ និង Latency | TraceQL |

### ២.៧ ការយល់ដឹងអំពីការកំណត់រចនាសម្ព័ន្ធ (Configuration) សម្រាប់ Loki និង Tempo

មុននឹងយើងឈានដល់ការសរសេរកូដក្នុងជំពូកទី ៣ យើងត្រូវយល់ពីរបៀបដែលឧបករណ៍ទាំងពីរនេះរៀបចំទិន្នន័យជាមុនសិន។

#### ១. ការកំណត់រចនាសម្ព័ន្ធ Grafana Loki
Loki ប្រើប្រាស់ឯកសារ YAML សម្រាប់កំណត់រចនាសម្ព័ន្ធ។ ចំណុចសំខាន់ៗមានដូចជា៖

*   **Auth Enabled:** ជាធម្មតាកំណត់ជា `false` សម្រាប់ Lab ប៉ុន្តែក្នុង Production គេប្រើវាសម្រាប់បែងចែក Tenant (ក្រុមហ៊ុន ឬក្រុមផ្សេងគ្នា)។
*   **Server:** កំណត់លេខ Port (ធម្មតា HTTP: `3100`)។
*   **Storage Config:** នេះជាចំណុចពិសេស! Loki មិនត្រូវការ Database ថ្លៃៗទេ។ អ្នកអាចកំណត់ឱ្យវាផ្ទុក logs ក្នុង៖
    *   `filesystem`: សម្រាប់ Lab (ផ្ទុកក្នុងម៉ាស៊ីនផ្ទាល់)។
    *   `s3` ឬ `gcs`: សម្រាប់ Production (ផ្ទុកក្នុង Cloud Storage ដែលមានតម្លៃថោក)។
*   **Schema Config:** កំណត់របៀបធ្វើ Index និងកាលបរិច្ឆេទចាប់ផ្តើមប្រើប្រាស់។

#### ២. ការកំណត់រចនាសម្ព័ន្ធ Grafana Tempo
Tempo ត្រូវបានរចនាឡើងឱ្យផ្ទុកទិន្នន័យ Traces ដ៏មហាសាលដោយមិនចាំបាច់ប្រើ Index ច្រើន (Indexless architecture)។

*   **Distributor:** ទទួលទិន្នន័យ Traces ពី Microservices (គាំទ្រ Protocol ច្រើនដូចជា OpenTelemetry, Jaeger, Zipkin)។
*   **Ingester:** ធ្វើការចងក្រង Traces ទុកក្នុង Memory មុននឹងបញ្ជូនទៅ Storage។
*   **Storage:** ដូច Loki ដែរ Tempo ខ្លាំងបំផុតនៅពេលប្រើជាមួយ Object Storage (S3/GCS)។
*   **Compactor:** ជួយបង្រួមទិន្នន័យ Traces ចាស់ៗឱ្យមានទំហំតូច ដើម្បីកាត់បន្ថយការចំណាយ Storage។

#### ទំនាក់ទំនងជាមួយ Grafana Dashboard
ដើម្បីឱ្យ Grafana មើលឃើញ Loki និង Tempo អ្នកត្រូវបន្ថែមពួកវាជា **Data Sources**។ នៅក្នុងការកំណត់រចនាសម្ព័ន្ធ Grafana អ្នកអាចប្រើមុខងារ **Derived Fields** ដើម្បីបង្កើត Link ស្វ័យប្រវត្តិ៖
*   នៅពេលមើល Logs ក្នុង Loki បើឃើញមាន `traceID` នោះ Grafana នឹងបង្ហាញប៊ូតុងមួយឱ្យអ្នកចុចដើម្បីទៅមើល Trace ក្នុង Tempo ភ្លាមៗ។

# ជំពូកទី ៣៖ ការរៀបចំ Environment ជាក់ស្តែងជាមួយ Docker Compose

ដើម្បីសិក្សាពី LGTM Stack ឱ្យមានប្រសិទ្ធភាព យើងនឹងប្រើប្រាស់ **Docker Compose** ដើម្បីរៀបចំ Lab Environment នៅលើម៉ាស៊ីនផ្ទាល់ខ្លួន ឬលើ Server។

### ៣.១ ការតំឡើង Docker និង Docker Compose
មុននឹងចាប់ផ្តើម អ្នកត្រូវប្រាកដថាបានតំឡើង៖
1.  **Docker Engine:** សម្រាប់ដំណើរការ Containers។
2.  **Docker Compose:** សម្រាប់គ្រប់គ្រង Multi-container applications តាមរយៈឯកសារ YAML តែមួយ។

### ៣.២ ការយល់ដឹងពី Persistence Data (Volumes)
នៅក្នុង Docker Containers បើសិនជាអ្នកបិទ Container នោះទិន្នន័យនឹងត្រូវបាត់បង់។ ដូច្នេះ យើងត្រូវប្រើ **Volumes** ដើម្បីភ្ជាប់ Folder ក្នុងម៉ាស៊ីនពិត ទៅកាន់ Folder ក្នុង Container ដើម្បីរក្សាទុក Metrics និង Logs ឱ្យនៅដដែលទោះបីជា Container Restart ក៏ដោយ។

``` yaml
%%writefile docker-compose.yaml
version: "3.8"

services:
  # Grafana: Visualization Layer
  grafana:
    image: grafana/grafana:latest
    container_name: grafana
    ports:
      - "3000:3000"
    environment:
      - GF_AUTH_ANONYMOUS_ENABLED=true
      - GF_AUTH_ANONYMOUS_ORG_ROLE=Admin
    volumes:
      - grafana-storage:/var/lib/grafana
    networks:
      - monitoring

  # Prometheus: Metrics Storage
  prometheus:
    image: prom/prometheus:latest
    container_name: prometheus
    ports:
      - "9090:9090"
    volumes:
      - ./prometheus.yml:/etc/prometheus/prometheus.yml
      - prometheus-storage:/prometheus
    networks:
      - monitoring

  # Loki: Log Aggregation
  loki:
    image: grafana/loki:latest
    container_name: loki
    ports:
      - "3100:3100"
    command: -config.file=/etc/loki/local-config.yaml
    networks:
      - monitoring

  # Tempo: Tracing Storage
  tempo:
    image: grafana/tempo:latest
    container_name: tempo
    command: [ "-config.file=/etc/tempo.yaml" ]
    ports:
      - "3200:3200"
      - "4317:4317"
    networks:
      - monitoring

networks:
  monitoring:
    driver: bridge

volumes:
  grafana-storage:
  prometheus-storage:
```

### ៣.៤ ការផ្ទៀងផ្ទាត់ដំណើរការនៃសេវាកម្ម

បន្ទាប់ពីសរសេរឯកសារ `docker-compose.yaml` រួច អ្នកអាចដំណើរការវាបានតាមរយៈពាក្យបញ្ជា៖

```bash
docker-compose up -d
```

**របៀបឆែកមើលស្ថានភាព៖**
*   **Grafana:** ចូលទៅកាន់ `http://localhost:3000` (User/Pass លំនាំដើមគឺ `admin`/`admin`)។
*   **Prometheus:** ចូលទៅកាន់ `http://localhost:9090`។
*   **Loki:** ឆែកមើលតាមរយៈ API `http://localhost:3100/ready`។

# ជំពូកទី ៤៖ ការប្រមូល និងវិភាគ Metrics ជាមួយ Prometheus + Exporters

Prometheus គឺជាបេះដូងនៃ Monitoring system របស់យើង។ នៅក្នុងជំពូកនេះ យើងនឹងសិក្សាពីរបៀបដែល Prometheus ធ្វើការប្រមូលទិន្នន័យ (Metrics) ពីប្រភពផ្សេងៗគ្នា។

### ៤.១ ស្វែងយល់ពី Prometheus Architecture

Prometheus ដំណើរការជាចម្បងតាមរយៈ **Pull Model**៖
*   **Pull Model:** Prometheus ដើរតួជាអ្នកទៅសួរ (Scrape) ទិន្នន័យពីសេវាកម្មនីមួយៗតាមកាលកំណត់។
*   **Pushgateway:** ប្រើសម្រាប់តែ Short-lived jobs (កម្មវិធីដែលដំណើរការហើយបិទទៅវិញភ្លាម) ដែលមិនអាចឱ្យ Prometheus ទៅ Pull ទិន្នន័យទាន់។

**សមាសភាគសំខាន់ៗ៖**
*   **Targets:** គឺជា HTTP endpoints (ជាទូទៅគឺ `/metrics`) ដែលបញ្ចេញទិន្នន័យជាទម្រង់ Text-based ធម្មតា។
*   **Exporters:** គឺជាភ្នាក់ងារដែលបំប្លែង Metrics ពីប្រព័ន្ធដែលមិនមែនជា Prometheus-native (ដូចជា MySQL, Linux Kernel) ឱ្យទៅជាទម្រង់ដែល Prometheus អាចអានបាន។

``` yaml
%%writefile prometheus.yml
global:
  scrape_interval: 15s # កំណត់ឱ្យទាញយក metrics រៀងរាល់ ១៥ វិនាទី
  evaluation_interval: 15s

scrape_configs:
  # តាមដានខ្លួនឯង (Prometheus monitoring itself)
  - job_name: "prometheus"
    static_configs:
      - targets: ["localhost:9090"]

  # តាមដាន Node Exporter (Metrics របស់ OS/Server)
  - job_name: "node-exporter"
    static_configs:
      - targets: ["node-exporter:9100"]

  # តាមដាន cAdvisor (Metrics របស់ Docker Containers)
  - job_name: "cadvisor"
    static_configs:
      - targets: ["cadvisor:8080"]
```

### ការពន្យល់អំពីឯកសារ prometheus.yml

*   **global**: កំណត់ Default setting សម្រាប់រាល់ការ Scrape ទាំងអស់។ `scrape_interval: 15s` មានន័យថាទិន្នន័យនឹងត្រូវបាន Update រៀងរាល់ ១៥ វិនាទីម្តង។
*   **scrape_configs**: ជាកន្លែងដែលយើងបញ្ជាក់ថា តើត្រូវទៅយក Metrics ពីណាខ្លះ។
*   **job_name**: ជាឈ្មោះសម្គាល់ក្រុមនៃ Metrics នីមួយៗ (ងាយស្រួលក្នុងការ Query ក្នុង Grafana)។
*   **targets**: ជាអាសយដ្ឋាន IP ឬឈ្មោះ Service ក្នុង Docker Network រួមជាមួយ Port របស់វា។

### ៤.២ ការកំណត់រចនាសម្ព័ន្ធសម្រាប់ Infrastructure Monitoring

ដើម្បីទទួលបាន Observability ពេញលេញលើ Infrastructure យើងត្រូវការ Exporters ពីរដែលសំខាន់បំផុត៖

#### ១. Node Exporter (OS-level Metrics)
វាផ្ដោតលើការតាមដាន Hardware និង OS metrics របស់ម៉ាស៊ីនពិត (Host)៖
*   **CPU usage:** `node_cpu_seconds_total`
*   **Memory usage:** `node_memory_MemAvailable_bytes`
*   **Disk usage:** `node_filesystem_size_bytes`
*   **Network traffic:** `node_network_receive_bytes_total`

#### ២. cAdvisor (Container-level Metrics)
វាត្រូវបានបង្កើតឡើងដោយ Google ដើម្បីវិភាគ Resource របស់ Container នីមួយៗ៖
*   **Container CPU:** `container_cpu_usage_seconds_total`
*   **Container Memory:** `container_memory_usage_bytes`
*   **Container Status:** តាមដានថាតើ Container ណាខ្លះកំពុងដំណើរការ ឬស្លាប់។

``` yaml
# នេះគឺជាផ្នែកនៃកូដដែលត្រូវបន្ថែមក្នុង services: នៃ docker-compose.yaml

# Node Exporter Service
# node-exporter:
#   image: prom/node-exporter:latest
#   volumes:
#     - /proc:/host/proc:ro
#     - /sys:/host/sys:ro
#     - /:/rootfs:ro

# cAdvisor Service
# cadvisor:
#   image: gcr.io/cadvisor/cadvisor:latest
#   volumes:
#     - /:/rootfs:ro
#     - /var/run:/var/run:ro
#     - /sys:/sys:ro
#     - /var/lib/docker/:/var/lib/docker:ro
```

បន្ទាប់ពីយើងបានរៀបចំ Config ទាំង Prometheus, Node Exporter និង cAdvisor រួចរាល់ហើយ ជំហានបន្ទាប់គឺការរៀនប្រើប្រាស់ **PromQL** ដើម្បីទាញទិន្នន័យមកបង្ហាញ។

### ៤.៤ មូលដ្ឋានគ្រឹះនៃភាសា PromQL (Prometheus Query Language)

PromQL គឺជា Functional Query Language ដែលអនុញ្ញាតឱ្យអ្នកជ្រើសរើស និងបូកសរុបទិន្នន័យ Time-series ក្នុង Real-time។

#### ១. ប្រភេទនៃទិន្នន័យ (Data Types)
*   **Instant Vector:** ជាសំណុំនៃទិន្នន័យដែលបង្ហាញតម្លៃចុងក្រោយបំផុត (ឧទាហរណ៍៖ CPU ពេលនេះ)។
*   **Range Vector:** ជាសំណុំនៃទិន្នន័យក្នុងចន្លោះពេលណាមួយ (ឧទាហរណ៍៖ ទិន្នន័យ CPU ក្នុងរយៈពេល ៥ នាទីចុងក្រោយ)។

#### ២. ប្រភេទនៃ Metrics
*   **Counter:** តម្លៃដែលកើនឡើងរហូត (ឧទាហរណ៍៖ ចំនួន Request សរុប)។ ប្រើជាមួយ `rate()` ដើម្បីរកល្បឿន។
*   **Gauge:** តម្លៃដែលឡើងចុះ (ឧទាហរណ៍៖ ការប្រើប្រាស់ RAM)។
*   **Histogram/Summary:** ប្រើសម្រាប់វាស់ Latency ឬទំហំ Request។

#### ៣. សញ្ញាប្រមាណវិធីដែលប្រើញឹកញាប់ (Common Operators)
*   `rate()`: គណនាអត្រាកំណើនជាមធ្យមក្នុងមួយវិនាទី (ប្រើសម្រាប់ Counter)។
*   `sum()`: បូកសរុបតម្លៃទាំងអស់។
*   `avg()`: រកតម្លៃមធ្យម។
*   `by (label)`: គ្រុប (Group) ទិន្នន័យតាម Label ដូចជា `by (instance)` ឬ `by (container_name)`。

``` yaml
# ឧទាហរណ៍នៃ PromQL Queries សំខាន់ៗ៖

# ១. រកអត្រា Request ក្នុងមួយវិនាទី (ក្នុងរយៈពេល ៥ នាទីចុងក្រោយ)
# rate(http_requests_total[5m])

# ២. រកការប្រើប្រាស់ CPU ជាភាគរយសម្រាប់ Container នីមួយៗ
# sum(rate(container_cpu_usage_seconds_total[5m])) by (container_name) * 100

# ៣. រក RAM ដែលនៅទំនេរលើ Server (គិតជា GB)
# node_memory_MemAvailable_bytes / (1024 * 1024 * 1024)
```
យើងបានបញ្ចប់ជំពូកទី ៤ ហើយ! ឥឡូវនេះអ្នកមានទាំង Stack Monitoring និងចំណេះដឹងមូលដ្ឋានលើការ Query metrics។

# ជំពូកទី ៥៖ ការគ្រប់គ្រង Logs រួមគ្នាជាមួយ Loki និង Promtail

ខណៈពេលដែល Metrics (Prometheus) ប្រាប់យើងថាមានបញ្ហា Logs (Loki) នឹងប្រាប់យើងថាតើបញ្ហានោះជាអ្វី។ ក្នុងជំពូកនេះ យើងនឹងសិក្សាពីការរៀបចំប្រព័ន្ធ Logs បែបទំនើបដែលប្រើប្រាស់ Resource តិចបំផុត។

### ៥.១ Architecture របស់ Loki: ហេតុអ្វីវាលឿន និងចំណាយតិច?

Loki ខុសពីប្រព័ន្ធ Logs ផ្សេងៗ (ដូចជា Elasticsearch) ដោយសារវាមានគោលការណ៍ **"Label-based Indexing"**:
*   **Index Less, Scale More:** Loki មិនធ្វើ Index លើរាល់ពាក្យក្នុង Log ឡើយ។ វាធ្វើ Index តែលើ Labels (metadata) ដូចជា `app`, `job`, `env`, ឬ `container`។ នេះមានន័យថាទំហំ Index របស់ Loki តូចជាង Elasticsearch រាប់សិបដង។
*   **Cheap Storage:** ដោយសារ Index មានទំហំតូច ទិន្នន័យ Logs អាចត្រូវបានបង្ហាប់ (Compressed) និងរក្សាទុកក្នុង Object Storage (S3/GCS) ក្នុងតម្លៃទាបបំផុត។
*   **Seamless Integration:** វាប្រើ Labels ដូចគ្នាទៅនឹង Prometheus ដែលធ្វើឱ្យយើងងាយស្រួលក្នុងការឆែកមើល Logs របស់ Service ណាដែលកំពុងមាន High Metrics Error (Correlation)។

``` yaml
%%writefile promtail-config.yml
server:
  http_listen_port: 9080
  grpc_listen_port: 0

positions:
  filename: /tmp/positions.yaml # រក្សាទុកចំណុចចុងក្រោយដែលអាន log រួច ដើម្បីកុំឱ្យអានជាន់គ្នាពេល restart

clients:
  - url: http://loki:3100/loki/api/v1/push

scrape_configs:
- job_name: container_logs
  static_configs:
  - targets:
      - localhost
    labels:
      job: containerlogs
      __path__: /var/lib/docker/containers/*/*.log # អាន logs ទាំងអស់របស់ Docker containers

  pipeline_stages:
  - json: # ប្រសិនបើ log ជាទម្រង់ JSON យើងអាចដកស្រង់ព័ត៌មានបាន
      expressions:
        stream: stream
        attrs: attrs
        tag: attrs.tag
  - labels:
      tag:
```

### ៥.៣ ការប្រើប្រាស់ LogQL ដើម្បីស្វែងរកទិន្នន័យ

LogQL មានទម្រង់ស្រដៀងនឹង PromQL ដែរ។ វាត្រូវបានបែងចែកជាពីរផ្នែកសំខាន់ៗ៖

#### ១. Log Stream Selector
ជ្រើសរើស Log តាមរយៈ Labels៖
*   `{container="payment-service"}`
*   `{job="varlogs", env="prod"}`

#### ២. Log Pipeline Operators
ប្រើសម្រាប់ Filter ឬបំប្លែងអត្ថបទ (Text) ក្នុង Log៖
*   **Filter expressions:**
    *   `|=` (មានពាក្យ): `{app="frontend"} |= "error"`
    *   `!=` (មិនមានពាក្យ): `{app="frontend"} != "debug"`
    *   `|~` (ប្រើ Regex): `{app="api"} |~ "timeout|connection"`
*   **Parser expressions:**
    *   `| json` (បំប្លែង log ពី text ទៅជា json fields ដើម្បីស្រួល Query)

**ឧទាហរណ៍ Query កម្រិតខ្ពស់:**
*   រាប់ចំនួន logs ដែលមានពាក្យថា error ក្នុងរយៈពេល ៥ នាទី:
    `count_over_time({job="varlogs"} |= "error" [5m])`
*   ស្វែងរក Request ដែលចំណាយពេលយូរជាង ១ វិនាទី (បើ log មាន json field `duration`):
    `{app="api"} | json | duration > 1000`

### ៥.៤ ការតភ្ជាប់ Loki ទៅកាន់ Grafana សម្រាប់ Visualization

ដើម្បីឱ្យ Grafana អាចបង្ហាញ Logs ពី Loki បាន យើងត្រូវបន្ថែមវាជា **Data Source**។ អ្នកអាចធ្វើវាបានតាមពីររបៀប៖

#### ១. ការកំណត់តាមរយៈ Grafana UI
1. ចូលទៅកាន់ Grafana (http://localhost:3000)។
2. ចូលទៅកាន់ **Connections** > **Data Sources**។
3. ចុច **Add data source** រួចជ្រើសរើសយក **Loki**។
4. ក្នុងប្រអប់ URL វាយបញ្ចូលអាសយដ្ឋាន៖ `http://loki:3100` (ដោយសារវាដំណើរការក្នុង Docker Network តែមួយ)។
5. ចុច **Save & Test**។

#### ២. ការកំណត់តាមរយៈ Configuration (Infrastructure as Code)
ប្រសិនបើអ្នកចង់ឱ្យ Grafana ស្គាល់ Loki ភ្លាមៗនៅពេល Start Container អ្នកអាចបង្កើតឯកសារកំណត់រចនាសម្ព័ន្ធស្វ័យប្រវត្តិ។

``` yaml
%%writefile grafana-datasources.yml
apiVersion: 1

datasources:
  - name: Loki
    type: loki
    access: proxy
    url: http://loki:3100
    version: 1
    editable: true
    # បង្កើត link រវាង Logs និង Traces (បើសិនជាមាន TraceID)
    jsonData:
      derivedFields:
        - datasourceUid: tempo
          matcherRegex: "traceID=(\\w+)"
          name: TraceID
          url: '$${__value.raw}'
```

### ៥.៥ ការទាញយក Metrics ចេញពី Logs (Log-based Metrics)

ចំណុចខ្លាំងមួយរបស់ Loki គឺសមត្ថភាពក្នុងការបំប្លែង Logs ឱ្យទៅជា Metrics ដើម្បីបង្ហាញក្នុង Graph។

**ឧទាហរណ៍៖** គណនាចំនួន HTTP 500 Error ចេញពី Logs ក្នុងរយៈពេល ១ នាទី:
`sum(count_over_time({app="api-gateway"} |= "500" [1m]))`

វានឹងបង្កើតជាក្រាហ្វបន្ទាត់ (Time-series) ដែលមើលទៅដូចជា Metrics របស់ Prometheus ដែរ ប៉ុន្តែវាបានមកពីការរាប់អត្ថបទក្នុង Logs។

# ជំពូកទី ៦៖ ការធ្វើ Distributed Tracing ជាមួយ Tempo

ប្រសិនបើ Metrics ប្រាប់ថាមានបញ្ហា ហើយ Logs ប្រាប់ថាជាបញ្ហាអ្វី នោះ **Tracing** នឹងប្រាប់អ្នកថា **តើបញ្ហានោះកើតឡើងនៅត្រង់ណា (Where exactly?)** នៅក្នុងខ្សែសង្វាក់នៃសេវាកម្មដ៏ស្មុគស្មាញ។

### ៦.១ មូលដ្ឋានគ្រឹះនៃ Tracing: Span, Trace និង Context Propagation

*   **Span:** គឺជាឯកតាការងារតូចបំផុត (ឧទាហរណ៍៖ ការហៅ SQL query ឬ HTTP request)។ រាល់ Span នីមួយៗផ្ទុក Metadata ដូចជា `start_time`, `duration`, និង `attributes`។
*   **Trace:** គឺជាបណ្តុំនៃ Spans ដែលតភ្ជាប់គ្នាបង្កើតបានជា End-to-end journey នៃ Request មួយ។
*   **Context Propagation:** គឺជាបច្ចេកទេសដ៏សំខាន់បំផុត។ នៅពេល Service A ហៅទៅ Service B វានឹងផ្ញើ `TraceID` តាមរយៈ HTTP Headers (ដូចជា `traceparent`) ដើម្បីឱ្យ Service B ដឹងថាវាជាផ្នែកមួយនៃ Trace តែមួយ។

### ៦.២ ហេតុអ្វីត្រូវប្រើ Grafana Tempo?

Tempo គឺជា **High-scale Object Storage** សម្រាប់ Traces ដែលមានសមត្ថភាពខ្ពស់៖
*   **Index-less Architecture:** Tempo មិនធ្វើ Index លើទិន្នន័យ Trace ទាំងមូលទេ ដែលធ្វើឱ្យវាស៊ី Resource តិច និងអាចផ្ទុកទិន្នន័យបានរាប់លានក្នុងមួយវិនាទី។
*   **TraceQL:** គឺជាភាសា Query ថ្មីដែលអនុញ្ញាតឱ្យអ្នកស្វែងរក Traces តាមរយៈលក្ខណៈសម្បត្តិលម្អិត (ឧទាហរណ៍៖ ស្វែងរក Traces ដែលមាន Latency > 2s ក្នុង Service ជាក់លាក់មួយ)។

``` yaml
%%writefile tempo.yaml
server:
  http_listen_port: 3200

distributor:
  receivers:
    otlp:
      protocols:
        grpc: # Port 4317 សម្រាប់ OpenTelemetry gRPC
        http: # Port 4318 សម្រាប់ OpenTelemetry HTTP

ingester:
  max_block_duration: 5m

storage:
  trace:
    backend: local
    local:
      path: /tmp/tempo/traces
    wal:
      path: /tmp/tempo/wal # Write Ahead Log សម្រាប់ការពារការបាត់បង់ទិន្នន័យ

overrides:
  metrics_generator_processors: [service-graphs, span-metrics] # បង្កើត metrics ស្វ័យប្រវត្តិពី traces
```

### ៦.៣ ការបញ្ចូល Instrumentation (OpenTelemetry)

ដើម្បីទទួលបាន Traces យើងត្រូវធ្វើ **Instrumentation** លើ Application របស់យើង៖
1.  **Auto-instrumentation:** ប្រើប្រាស់ភ្នាក់ងារ (Agent) ដើម្បីចាប់យក Spans ដោយមិនចាំបាច់កែប្រែកូដ (ស័ក្តិសមសម្រាប់ Java, Python, Node.js)។
2.  **Manual Instrumentation:** សរសេរកូដបន្ថែមដោយប្រើ OTel SDK ដើម្បីចាប់យក Logic អាជីវកម្មជាក់លាក់។

### ៦.៤ ការវិភាគ Latency និងការមើល Trace ក្នុង Grafana

បន្ទាប់ពីយើងបានតំឡើង Tempo រួចរាល់ យើងអាចប្រើប្រាស់ **Explore** tab ក្នុង Grafana ដើម្បីរុករក Traces ទាំងនោះ។

#### ១. របៀបស្វែងរក Trace
*   ចូលទៅកាន់ **Explore** រួចជ្រើសរើស Data Source ជា **Tempo**។
*   អ្នកអាចស្វែងរកតាមរយៈ **Trace ID** (ដែលទទួលបានពី Logs) ឬប្រើមុខងារ **Search** ដើម្បីមើល Traces ថ្មីៗបំផុត។

#### ២. ការយល់ដឹងពី Waterfall View
នៅពេលអ្នកបើក Trace មួយ អ្នកនឹងឃើញក្រាហ្វប្រភេទ Waterfall៖
*   **Root Span:** ជា Span ដំបូងគេ (ធម្មតាជា API Gateway ឬ Frontend)។
*   **Child Spans:** ជាប្រតិបត្តិការបន្តបន្ទាប់។ ប្រសិនបើ Span មួយមានពណ៌វែងជាងគេ នោះមានន័យថាវាចំណាយពេលយូរជាងគេ (Bottleneck)។

#### ៣. ការធ្វើ Service Graph
Tempo អាចបង្កើតរូបភាពបណ្តាញសេវាកម្ម (Service Graph) ឱ្យអ្នកឃើញដោយស្វ័យប្រវត្តិ។ វាបង្ហាញពីទំនាក់ទំនងរវាង Service A ទៅ Service B និងប្រាប់ពីកម្រិត Error ក៏ដូចជា Latency នៃខ្សែភ្ជាប់នីមួយៗ។

```yaml
# ឧទាហរណ៍៖ ការកំណត់ Tempo ជា Data Source ក្នុង grafana-datasources.yml
# (បន្ថែមចូលក្នុងឯកសារដែលយើងបានបង្កើតក្នុងជំពូកទី ៥)

#  - name: Tempo
#    type: tempo
#    access: proxy
#    url: http://tempo:3200
#    jsonData:
#      httpMethod: GET
#      serviceMap:
#        datasourceUid: 'prometheus' # ប្រើ Prometheus ដើម្បីបង្កើត Service Graph
```

### ៦.៥ វិធីសាស្រ្តដោះស្រាយបញ្ហា (Troubleshooting) ពេលមិនឃើញ Traces

ប្រសិនបើអ្នកបានរៀបចំគ្រប់យ៉ាងហើយ ប៉ុន្តែនៅតែមិនឃើញ Traces ក្នុង Grafana Explore អ្នកគួរពិនិត្យមើលចំណុចដូចខាងក្រោម៖

#### ១. ពិនិត្យមើល Receiver Protocols ក្នុង Tempo
ត្រូវប្រាកដថា Microservices របស់អ្នកកំពុងផ្ញើទិន្នន័យតាម Protocol ដែល Tempo គាំទ្រ (ដូចជា OTLP gRPC តាម Port 4317)។

#### ២. បញ្ហា Network ក្នុង Docker Compose
ក្នុងប្រព័ន្ធ Microservices, Container នីមួយៗត្រូវតែស្ថិតក្នុង Network តែមួយជាមួយ Tempo។ ប្រសិនបើកម្មវិធីរបស់អ្នកផ្ញើទៅកាន់ `localhost:4317` វានឹងបរាជ័យ ព្រោះវាត្រូវផ្ញើទៅកាន់ `tempo:4317` វិញ។

#### ៣. ពិនិត្យមើល Tempo Ingester Logs
អ្នកអាចប្រើពាក្យបញ្ជា Docker ដើម្បីមើលថា តើ Tempo ទទួលបានទិន្នន័យដែរឬទេ៖
`docker logs tempo`
ស្វែងរកពាក្យថា "Trace added" ឬ Error ផ្សេងៗទាក់ទងនឹងការសរសេរទិន្នន័យចូល Storage។

#### ៤. ចំណុចសំខាន់៖ Trace Sampling
ពេលខ្លះ Traces មិនត្រូវបានផ្ញើទៅគ្រប់ Request ទាំងអស់ទេ (ដើម្បីកុំឱ្យធ្ងន់ប្រព័ន្ធ)។ សម្រាប់ការតេស្ត អ្នកគួរកំណត់ Sampling Rate ឱ្យដល់ **1.0 (100%)** ដើម្បីឱ្យគ្រប់ Request ទាំងអស់ត្រូវបានកត់ត្រា។

``` yaml
# គន្លឹះ៖ ការឆែកមើល Connection រវាង Application និង Tempo តាមរយៈ curl
# curl -v http://tempo:3200/ready

# ប្រសិនបើលទ្ធផលបង្ហាញថា "ready" នោះមានន័យថា Tempo ដំណើរការធម្មតា
# ប៉ុន្តែបើទិន្នន័យមិនចូល អាចមកពី Configuration របស់ OpenTelemetry ក្នុង Application របស់អ្នក។
```

# ជំពូកទី ៧៖ ការបង្កើត Dashboards ប្រកបដោយវិជ្ជាជីវៈ (Best Practices)

Dashboard ដែលល្អ មិនមែនជា Dashboard ដែលមានក្រាហ្វច្រើននោះទេ ប៉ុន្តែជា Dashboard ដែលអាចឆ្លើយសំណួរបានភ្លាមៗថា **"តើប្រព័ន្ធមានបញ្ហាឬអត់? ហើយបញ្ហានៅត្រង់ណា?"**

### ៧.១ ការរចនា Dashboard តាមគោលការណ៍ "Golden Signals"

Google SRE បានណែនាំនូវសញ្ញាសំខាន់ៗចំនួន ៤ ដែលអ្នកគួរតែមាននៅលើ Dashboard សម្រាប់រាល់ Service នីមួយៗ៖

1.  **Latency (ភាពយឺត):** រយៈពេលដែល Request មួយចំណាយ។
    *   *Tip:* កុំប្រើមធ្យមភាគ (Average) តែមួយមុខ។ ត្រូវប្រើ **Percentiles (P95, P99)** ដើម្បីមើលឃើញ Request ដែលយឺតបំផុតដែលប៉ះពាល់ដល់ User បទពិសោធន៍។
2.  **Traffic (ចរាចរណ៍):** កម្រិតនៃការប្រើប្រាស់ប្រព័ន្ធ (ឧទាហរណ៍៖ HTTP Requests per second)។
3.  **Errors (កំហុស):** អត្រានៃការបរាជ័យ (ឧទាហរណ៍៖ HTTP 500 errors)។ គណនាជាភាគរយធៀបនឹង Traffic សរុប។
4.  **Saturation (ការឆ្អែត):** កម្រិតនៃការប្រើប្រាស់ Resources (CPU, RAM, I/O)។ វាប្រាប់យើងថាតើប្រព័ន្ធជិតពេញសមត្ថភាពហើយឬនៅ។

``` yaml
# ឧទាហរណ៍៖ ការប្រើប្រាស់ PromQL សម្រាប់ Golden Signals

# ១. គណនា P95 Latency (ក្នុងរយៈពេល ៥ នាទី)
# histogram_quantile(0.95, sum(rate(http_request_duration_seconds_bucket[5m])) by (le, job))

# ២. គណនា Error Rate ជាភាគរយ (%)
# (sum(rate(http_requests_total{status=~"5.."}[5m])) / sum(rate(http_requests_total[5m]))) * 100

# ៣. ការប្រើប្រាស់ Variable ក្នុង Query ($service_name គឺជា variable)
# rate(http_requests_total{job="$service_name"}[5m])
```
### ៧.៣ បច្ចេកទេសរៀបចំ និងការប្រើប្រាស់ Variables

ដើម្បីឱ្យ Dashboard ងាយស្រួលអាន យើងគួរអនុវត្តតាមបច្ចេកទេសខាងក្រោម៖

*   **Grouping with Rows:** រៀបចំ Panel ជាក្រុមៗ (ឧទាហរណ៍៖ Row ឈ្មោះ "Application Health" និង Row ឈ្មោះ "Infrastructure Settings")។
*   **Dynamic Variables:** បង្កើត Dropdown សម្រាប់ជ្រើសរើស `Environment` (Dev/Prod) និង `Service Name`។
    *   *Query សម្រាប់ Variable:* `label_values(up, job)`
*   **Thresholds:** កំណត់ពណ៌ឱ្យក្រាហ្វ (ឧទាហរណ៍៖ បើ Latency > 500ms ឱ្យវាបង្ហាញពណ៌ក្រហម) ដើម្បីឱ្យយើងចាប់អារម្មណ៍ភ្លាមៗ។

### ៧.៤ បច្ចេកទេសរៀបចំ Row និង Panel ឱ្យមានរបៀបរៀបរយ

នៅពេល Dashboard របស់អ្នកចាប់ផ្តើមធំទៅៗ ការរៀបចំឱ្យមានសណ្តាប់ធ្នាប់គឺជាគន្លឹះនៃប្រសិទ្ធភាព៖

*   **ការប្រើប្រាស់ Rows:** ប្រើ Rows ដើម្បីបែងចែកក្រុមនៃ Panels (ឧទាហរណ៍៖ Row សម្រាប់ Metrics, Row សម្រាប់ Logs, Row សម្រាប់ Infrastructure)។ អ្នកអាចបិទ (Collapse) Row ដែលមិនទាន់ត្រូវការមើល ដើម្បីកុំឱ្យធ្ងន់ Browser។
*   **ការដាក់ឈ្មោះ Panel:** ឈ្មោះ Panel គួរតែខ្លីខ្លឹម និងប្រាប់ពីអ្វីដែលវាកំពុងបង្ហាញ (ឧទាហរណ៍៖ `HTTP Error Rate (5xx)`)។
*   **Panel Links:** បង្កើត Link នៅក្នុង Panel មួយ ដើម្បីឱ្យអ្នកប្រើប្រាស់អាចចុចទៅកាន់ Dashboard ផ្សេងទៀតដែលមានព័ត៌មានលម្អិតជាងនេះ (Drill-down approach)។

### ៧.៥ ការប្រើប្រាស់ Library Panels (Reusability)

ប្រសិនបើអ្នកមាន Panel មួយដែលត្រូវប្រើក្នុង Dashboards ច្រើន (ឧទាហរណ៍៖ ក្បាល Dashboard ដែលបង្ហាញ Uptime) អ្នកមិនចាំបាច់បង្កើតវាឡើងវិញរាល់ដងទេ៖

1.  បង្កើត Panel នោះក្នុង Dashboard មួយ។
2.  ចុចលើ Options រួចជ្រើសរើស **"Create library panel"**។
3.  ក្នុង Dashboard ថ្មី អ្នកគ្រាន់តែចុច **Add** > **Library Panel** រួចជ្រើសរើសយក Panel ដែលបានរក្សាទុកជាការស្រេច។

> **Pro-Tip:** នៅពេលអ្នកកែប្រែ Library Panel តែមួយ វានឹង Update គ្រប់ Dashboards ទាំងអស់ដែលប្រើប្រាស់ Panel នោះដោយស្វ័យប្រវត្តិ។

# ជំពូកទី ៨៖ ការរៀបចំ Alerting System និងការគ្រប់គ្រងការជូនដំណឹង

Alerting គឺជាសមត្ថភាពរបស់ប្រព័ន្ធក្នុងការផ្ញើសារដំណឹងទៅកាន់អ្នកបច្ចេកទេស នៅពេលដែលមានភាពមិនប្រក្រតីកើតឡើង។ Alert ដែលល្អ ត្រូវតែមានភាពជាក់លាក់ និងអាចដោះស្រាយបាន (Actionable)។

### ៨.១ ការបង្កើត Alert Rules ប្រកបដោយប្រសិទ្ធភាព

នៅក្នុង Grafana ទំនើប យើងប្រើ **Unified Alerting** ដែលអនុញ្ញាតឱ្យយើងបង្កើតលក្ខខណ្ឌស្មុគស្មាញ៖

1.  **Reduce Noise (កាត់បន្ថយការរំខាន):** ជៀសវាងការបង្កើត Alert លើរឿងតូចតាច។ ប្រើប្រាស់ `For` duration (ឧទាហរណ៍៖ `5m`) ដើម្បីប្រាកដថាបញ្ហានោះពិតជាកើតឡើងជាប់គ្នា មិនមែនគ្រាន់តែជាការឡើងខ្ពស់ឆ្វាច់មួយភ្លែត (Spike)។
2.  **Multi-dimensional Alerting:** ប្រើ Labels ក្នុង Alert ដើម្បីបែងចែកកម្រិតធ្ងន់ធ្ងរ (Severity)។
    *   `severity=critical`: ផ្ញើទៅ Telegram/PagerDuty ភ្លាមៗ (ត្រូវការដោះស្រាយបន្ទាន់)។
    *   `severity=warning`: ផ្ញើត្រឹមតែ Slack ឬ Email (ពិនិត្យមើលតាមក្រោយបាន)។
3.  **Alert Fatigue:** កុំផ្ញើ Alert ដដែលៗច្រើនពេក។ កំណត់ `Group Wait` និង `Group Interval` ដើម្បីចងក្រង Alert ច្រើនដែលពាក់ព័ន្ធគ្នា ឱ្យទៅជាសារតែមួយ។

### ៨.២ ការកំណត់ Notification Policies និង Routing

Notification Policy គឺជាខួរក្បាលដែលសម្រេចចិត្តថា តើ Alert ណាត្រូវផ្ញើទៅណា និងពេលណា។

*   **Root Policy:** ជាគោលការណ៍លំនាំដើម (Default) ដែល Alert ទាំងអស់នឹងរត់កាត់។
*   **Specific Routing:** យើងអាចបង្កើត Rule បន្ថែម ឧទាហរណ៍៖
    *   ប្រសិនបើ `team=database` ឱ្យផ្ញើទៅកាន់ DBA Team Telegram Group។
    *   ប្រសិនបើ `env=prod` ឱ្យផ្ញើទៅកាន់ SRE On-call Team។

### ៨.៣ ការសរសេរ Alert Templates ឱ្យមានព័ត៌មានគ្រប់គ្រាន់

សារដែលផ្ញើទៅ Telegram មិនគួរមានត្រឹមតែពាក្យថា "Server Down" នោះទេ។ វាគួរតែមាន៖
*   **Summary:** តើមានរឿងអ្វីកើតឡើង? (ឧទាហរណ៍៖ API Error Rate ខ្ពស់ពេក)
*   **Description:** តម្លៃជាក់ស្តែង (ឧទាហរណ៍៖ Error Rate គឺ 15% ដែលលើសពី 5%)
*   **Dashboard Link:** តំណភ្ជាប់ទៅកាន់ Grafana ដើម្បីមើលស្ថានភាពលម្អិតភ្លាមៗ។
*   **Runbook Link:** ឯកសារណែនាំពីរបៀបដោះស្រាយបញ្ហានេះ (Manual steps)។

### ៨.៤ ការរៀបចំ Contact Points (Telegram & Slack)

បន្ទាប់ពីអ្នកទទួលបាន **Bot Token** និង **Chat ID** ហើយ សូមអនុវត្តតាមជំហានទាំងនេះដើម្បីភ្ជាប់វាទៅក្នុង Grafana៖

1.  **ចូលទៅកាន់ Menu Alerting:** ចុចលើរូបកណ្ដឹងនៅ Sidebar ខាងឆ្វេង រួចជ្រើសរើសយក **Contact points**។
2.  **បង្កើត Contact Point ថ្មី:** ចុចប៊ូតុង **+ Add contact point** និងជ្រើសរើស **Telegram**។
3.  **បំពេញព័ត៌មាន:** បញ្ចូល Token និង Chat ID (កុំភ្លេចសញ្ញា `-` បើវាជា Group)។
4.  **ផ្ទៀងផ្ទាត់:** ចុចប៊ូតុង **Test** ដើម្បីបញ្ជាក់ថាការតភ្ជាប់ជោគជ័យ។

### ៨.៥ ការតេស្តផ្ញើសារទៅ Telegram តាមរយៈ API (Payload Testing)

មុននឹងបញ្ចូលទៅក្នុង Grafana អ្នកអាចសាកល្បងផ្ញើសារគំរូ (Sample Payload) តាមរយៈ Python ដើម្បីប្រាកដថា Bot របស់អ្នកមានសិទ្ធិផ្ញើសារចូល Group បានត្រឹមត្រូវ។

``` yaml
import requests
import json

# ១. បញ្ចូលព័ត៌មាន Bot របស់អ្នក
BOT_TOKEN = "YOUR_BOT_TOKEN_HERE"
CHAT_ID = "YOUR_CHAT_ID_HERE"

# ២. បង្កើតមុខងារផ្ញើសារដែលមាន Label ឌីណាមិក (Dynamic Labels)
def send_formatted_alert(severity, service_name, value):
    # កំណត់រូបតំណាងតាមកម្រិតធ្ងន់ធ្ងរ
    emoji = "🔥" if severity == "critical" else "⚠️"

    message = (
        f"{emoji} *Grafana Alert: {severity.upper()}* {emoji}\n\n"
        f"*Service:* {service_name}\n"
        f"*Value:* {value}\n"
        f"*Description:* The service {service_name} is experiencing {severity} issues.\n"
        f"*Time:* 2023-10-27 10:00:00 UTC\n\n"
        "[🔍 View in Grafana](http://localhost:3000)"
    )

    payload = {
        "chat_id": CHAT_ID,
        "text": message,
        "parse_mode": "Markdown"
    }

    url = f"https://api.telegram.org/bot{BOT_TOKEN}/sendMessage"

    try:
        response = requests.post(url, data=payload)
        if response.status_code == 200:
            print(f"[+] ជោគជ័យ! សារកម្រិត {severity} ត្រូវបានផ្ញើរួចរាល់។")
        else:
            print(f"[-] បរាជ័យ: {response.text}")
    except Exception as e:
        print(f"[-] មានបញ្ហាបច្ចេកទេស: {e}")

# តេស្តផ្ញើសារពីរប្រភេទ
send_formatted_alert("critical", "auth-service", "98% CPU")
send_formatted_alert("warning", "payment-gateway", "500ms Latency")
```
### ៨.៦ ការបង្កើត Alert Template ក្នុង Grafana (ជំនួសឱ្យ Python Script)

ដើម្បីឱ្យ Grafana ផ្ញើសារដែលមានទម្រង់ស្អាត (Formatted Message) ដូច Python script ដែលយើងបានតេស្ត អ្នកត្រូវបង្កើត **Message Template** តាមជំហានខាងក្រោម៖

1. ចូលទៅកាន់ **Alerting** > **Contact points** រួចជ្រើសរើស tab **Message templates**។
2. ចុច **+ Add message template** រួចដាក់ឈ្មោះថា `telegram_custom_template`។
3. នៅក្នុងផ្នែក **Content** សូមប្រើប្រាស់កូដខាងក្រោម (Go Templating):

```handlebars
{{ define "telegram_alert_message" }}
  {{ if eq .Status "firing" }}🔥{{ else }}✅{{ end }} *Grafana Alert: {{ .Status | upper }}* {{ if eq .Status "firing" }}🔥{{ else }}✅{{ end }}

  *Summary:* {{ .Annotations.summary }}
  *Service:* {{ .Labels.service_name }}
  *Severity:* {{ .Labels.severity }}
  
  {{ if gt (len .Alerts.Firing) 0 }}
    *Details:*
    {{ range .Alerts.Firing }}
      - {{ .Annotations.description }}
    {{ end }}
  {{ end }}

  [🔍 View in Grafana]({{ .ExternalURL }})
{{ end }}
```
4. បន្ទាប់មក ចូលទៅកែ **Contact Point** របស់ Telegram របស់អ្នក។
5. ក្នុងផ្នែក **Optional Telegram settings** រកមើលប្រអប់ **Message** រួចវាយបញ្ចូល៖ `{{ template "telegram_alert_message" . }}`
6. ចុច **Save** ជាការស្រេច។ ឥឡូវនេះ Grafana នឹងផ្ញើសារដែលមានទម្រង់ស្អាត និងឌីណាមិកតាម Labels ដូចអ្វីដែលយើងបានធ្វើក្នុង Python ដែរ។

# ជំពូកទី ៩៖ ការអនុវត្តផ្ទាល់ (Mini-Project)

នៅក្នុង Mini-Project នេះ យើងនឹងបង្កើតប្រព័ន្ធ Observability ពេញលេញសម្រាប់ Microservice គំរូមួយ។

### ៩.១ ការដាក់បញ្ចូល Instrumentation ទៅក្នុង Application

ដើម្បីឱ្យ Application បញ្ចេញ Metrics, Logs និង Traces យើងត្រូវប្រើ OpenTelemetry SDK។ ខាងក្រោមគឺជាឧទាហរណ៍នៃ Flow ក្នុង Application គំរូ៖

1.  **Logging:** កែសម្រួល Logger ឱ្យបញ្ចេញ Log ជាទម្រង់ JSON និងភ្ជាប់ជាមួយ `trace_id`។
2.  **Metrics:** បង្កើត Endpoint `/metrics` ដើម្បីឱ្យ Prometheus អាចទាញយកទិន្នន័យបាន។
3.  **Tracing:** កំណត់ OTLP Exporter ឱ្យផ្ញើ Spans ទៅកាន់ Tempo (Port 4317)។

``` yaml
# ឧទាហរណ៍៖ ការកំណត់រចនាសម្ព័ន្ធ OpenTelemetry ក្នុង Python
# from opentelemetry import trace
# from opentelemetry.exporter.otlp.proto.grpc.trace_exporter import OTLPSpanExporter
# from opentelemetry.sdk.trace import TracerProvider
# from opentelemetry.sdk.trace.export import BatchSpanProcessor

# otlp_exporter = OTLPSpanExporter(endpoint="http://tempo:4317", insecure=True)
# span_processor = BatchSpanProcessor(otlp_exporter)
# trace.get_tracer_provider().add_span_processor(span_processor)
```
### ៩.២ ការបង្កើត Full Observability Dashboard

គោលដៅគឺបង្កើត Dashboard តែមួយដែលមាន៖
*   ផ្នែកខាងលើ៖ **Stat Panels** បង្ហាញ Request rate និង Error rate សរុប។
*   ផ្នែកកណ្តាល៖ **Time Series** បង្ហាញ Latency (p95, p99)។
*   ផ្នែកខាងក្រោម៖ **Logs & Traces View** ដែលអនុញ្ញាតឱ្យយើងឆែកមើល Log នៅពេលមាន Error និងចុចមើល Trace ID ដើម្បីដឹងពី Bottleneck។

### ៩.៣ ការធ្វើតេស្តសាកល្បង (Verification)

1.  **Generate Traffic:** ប្រើប្រាស់ឧបករណ៍ដូចជា `k6` ឬ `ab` ដើម្បីបាញ់ Request ទៅកាន់ Application។
2.  **Simulate Errors:** បង្កើត Error សិប្បនិម្មិត (ឧទាហរណ៍៖ បិទ Database ឬផ្ញើ Input ខុស)។
3.  **Check Alerts:** ពិនិត្យមើលថាតើ Telegram/Slack ទទួលបានសារ Alert ដែរឬទេ?
4.  **Root Cause Analysis:** ប្រើ Dashboard ដើម្បីដានរកមូលហេតុ ចាប់ពី Metrics -> Logs -> Traces។


### ៩.៤ សេចក្តីសន្និដ្ឋាន និងជំហានបន្ទាប់

ការយល់ដឹងពី Grafana Stack (LGTM) នឹងធ្វើឱ្យអ្នកក្លាយជា DevOps/SRE ដែលមានសមត្ថភាពខ្ពស់។

**ជំហានបន្ទាប់ដែលអ្នកគួរធ្វើ៖**
*   សិក្សាអំពី **Grafana Phlare** សម្រាប់ Continuous Profiling។
*   រៀនប្រើ **Grafana OnCall** សម្រាប់ការគ្រប់គ្រងវេនប្រចាំការ (Incident Management)។
*   អនុវត្តការតំឡើងនៅលើ **Kubernetes** ដោយប្រើ Grafana Agent ឬ Prometheus Operator។

