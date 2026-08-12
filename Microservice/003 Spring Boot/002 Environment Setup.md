## ផ្នែកទី២៖ ការរៀបចំឧបករណ៍ (Environment Setup) និងការបង្កើតគម្រោងដំបូង (First Project) តាមរយៈ Spring Initializr

ការរៀបចំបរិយាកាសការងារឱ្យបានត្រឹមត្រូវ គឺជាជំហានគ្រឹះដ៏សំខាន់បំផុត។ ផ្នែកនេះនឹងពន្យល់លម្អិតអំពីឧបករណ៍នីមួយៗ និងរបៀបប្រើប្រាស់ឧបករណ៍ជំនួយដើម្បីចាប់ផ្តើមគម្រោងបានយ៉ាងរហ័ស។

### ១. ការរៀបចំឧបករណ៍ (Detailed Environment Setup)

ដើម្បីអភិវឌ្ឍន៍កម្មវិធី Spring Boot អ្នកត្រូវការឧបករណ៍ស្នូលចំនួន ៣ ដូចខាងក្រោម៖

1.  **Java Development Kit (JDK)**:
    *   **តួនាទី**: ជាម៉ាស៊ីនសម្រាប់បកប្រែកូដ និងដំណើរការកម្មវិធី Java ។ Spring Boot 3.x តម្រូវឱ្យមានយ៉ាងហោចណាស់ **JDK 17** ឬខ្ពស់ជាងនេះ។
    *   **ការជ្រើសរើស**: អ្នកអាចប្រើ **OpenJDK** (ឥតគិតថ្លៃ) ឬ **Oracle JDK** ។ បច្ចុប្បន្ន **Amazon Corretto** ឬ **Eclipse Temurin** ក៏ពេញនិយមខ្លាំងព្រោះវាមានស្ថេរភាព។
    *   **គន្លឹះសំខាន់**: ត្រូវប្រាកដថាបានកំណត់ `JAVA_HOME` នៅក្នុង System Variables ដើម្បីឱ្យ Command Prompt ស្គាល់បញ្ជា `java` និង `javac` ។

2.  **Integrated Development Environment (IDE)**:
    *   **IntelliJ IDEA**: ជា IDE ដែលល្អបំផុតសម្រាប់ Spring Boot ។ វាមានមុខងារ 'Smart Code Completion' ដែលជួយសរសេរកូដបានលឿន និងកាត់បន្ថយកំហុស។
    *   **VS Code**: ស្រាល និងរហ័ស។ ប្រសិនបើប្រើ VS Code ត្រូវដំឡើង **Extension Pack for Java** និង **Spring Boot Extension Pack** ។
    *   **Spring Tool Suite (STS)**: ជា IDE ពិសេសដែលកែច្នៃចេញពី Eclipse សម្រាប់តែអ្នកប្រើ Spring តែម្តង។

3.  **Build Automation Tool (Maven/Gradle)**:
    *   ឧបករណ៍ទាំងនេះជួយគ្រប់គ្រងបណ្ណាល័យ (Libraries) ដែលកម្មវិធីត្រូវការ។ Maven ប្រើឯកសារ `pom.xml` (XML) ចំណែក Gradle ប្រើ `build.gradle` (Groovy/Kotlin) ។ សម្រាប់អ្នកចាប់ផ្តើម Maven គឺងាយស្រួលយល់ជាង។

### ២. ការបង្កើតគម្រោងដំបូងតាមរយៈ Spring Initializr (Step-by-Step)

**Spring Initializr** (start.spring.io) គឺជា 'Project Generator' ដែលជួយរៀបចំគ្រោងឆ្អឹងរបស់កម្មវិធីឱ្យយើងស្រេច។

**ការកំណត់រចនាសម្ព័ន្ធលម្អិត:**
*   **Project**: ជ្រើសរើស **Maven** (ពេញនិយមសម្រាប់មេរៀនគ្រូ)។
*   **Language**: **Java** ។
*   **Spring Boot Version**: ជ្រើសរើសយកលេខដែលគ្មានពាក្យ (SNAPSHOT) ឬ (M1) ព្រោះវាជាកំណែដែលមានស្ថេរភាព (Stable Version) ។
*   **Metadata**: 
    *   `Group`: ជាធម្មតាប្រើឈ្មោះក្រុមហ៊ុន ឬ Domain បញ្ច្រាស (ឧទាហរណ៍ `com.khmerdeveloper`) ។
    *   `Artifact`: ឈ្មោះកម្មវិធីរបស់អ្នក (ឧទាហរណ៍ `pos-system`) ។
*   **Dependencies (ផ្នែកសំខាន់បំផុត)**:
    *   **Spring Web**: ចាំបាច់សម្រាប់បង្កើត Web API និងប្រើ Tomcat Server ។
    *   **Lombok**: ជួយកាត់បន្ថយការសរសេរ Getter/Setter ដោយដៃ (ជួយឱ្យកូដស្អាត)។
    *   **Spring Boot DevTools**: ធ្វើឱ្យកម្មវិធី Restart ស្វ័យប្រវត្តិពេលអ្នកកែរកូដ (ចំណេញពេល)។

បន្ទាប់ពីចុច **GENERATE** អ្នកនឹងទទួលបានឯកសារ ZIP ។ គ្រាន់តែពន្លា (Unzip) និងបើកវាជាមួយ IDE របស់អ្នក រួចរង់ចាំឱ្យវាទាញយកបណ្ណាល័យ (Download Dependencies) ជាការស្រេច។