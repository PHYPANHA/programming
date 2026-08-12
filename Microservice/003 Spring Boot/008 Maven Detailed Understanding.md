## ផ្នែកទី ៨៖ ការយល់ដឹងលម្អិតអំពី Maven (Detailed Understanding of Maven)

**Maven** គឺជាឧបករណ៍គ្រប់គ្រងគម្រោង (Project Management Tool) និងបង្កើតស្វ័យប្រវត្តិ (Build Automation Tool) ដែលប្រើសម្រាប់គម្រោង Java (Java Projects) ។ គោលបំណងចម្បងរបស់វាគឺដើម្បីស្តង់ដារ (Standardize) របៀបដែលគម្រោងត្រូវបានបង្កើត គ្រប់គ្រង Dependencies (Dependencies) និងដំណើរការ (Run) Test (Tests) ។

### ១. គោលបំណង និងតួនាទីរបស់ Maven (Purpose and Role of Maven)

*   **ការគ្រប់គ្រង Dependencies (Dependency Management)**:
    *   នេះគឺជាមុខងារដ៏សំខាន់បំផុតមួយរបស់ Maven ។ ជំនួសឲ្យការទាញយក (Download) និងបន្ថែម Jar Files (Jar Files) ដោយដៃទៅកាន់គម្រោងរបស់អ្នក Maven អនុញ្ញាតឲ្យអ្នកគ្រាន់តែប្រកាស (Declare) Dependencies នៅក្នុងឯកសារ `pom.xml` ។ Maven នឹងទាញយក Dependencies ទាំងនោះដោយស្វ័យប្រវត្តិពី Maven Repository (Maven Repository) ។
*   **វដ្តនៃការបង្កើតដែលបានកំណត់ទុកជាមុន (Predefined Build Lifecycle)**:
    *   Maven ផ្តល់នូវវដ្តនៃការបង្កើតស្តង់ដារ (Standard Build Lifecycle) ដូចជា Compile (Compile), Test (Test), Package (Package) និង Install (Install) ។ នេះធ្វើឲ្យដំណើរការបង្កើតមានភាពស៊ីសង្វាក់គ្នា (Consistent) សម្រាប់គម្រោងទាំងអស់។
*   **ការបង្កើតគម្រោងស្តង់ដារ (Standard Project Structure)**:
    *   Maven លើកទឹកចិត្តឲ្យមានរចនាសម្ព័ន្ធថតស្តង់ដារ (Standard Directory Structure) ដែលជួយឲ្យ Developers (Developers) ថ្មីអាចយល់ និងធ្វើការលើគម្រោងបានលឿន។
*   **ការបង្កើត Report (Reporting)**:
    *   វាអាចបង្កើត Reports (Reports) ផ្សេងៗអំពីគម្រោង ដូចជា Test Results (Test Results), Code Coverage (Code Coverage) និង Documentation (Documentation) ។
*   **កាត់បន្ថយការកំណត់រចនាសម្ព័ន្ធ (Reduced Configuration)**:
    *   ដោយសារវាមាន **Convention Over Configuration (Convention Over Configuration)** គឺអ្នកមិនចាំបាច់កំណត់រចនាសម្ព័ន្ធអ្វីច្រើននោះទេ។ ឧទាហរណ៍ វាដឹងថាកូដប្រភព (Source Code) ស្ថិតនៅក្នុង `src/main/java` និង Test Code (Test Code) ស្ថិតនៅក្នុង `src/test/java` ។

### ២. វដ្តនៃការបង្កើតរបស់ Maven (Maven Build Lifecycle)

វដ្តនៃការបង្កើតរបស់ Maven គឺជាបណ្តុំនៃដំណាក់កាល (Phases) ដែលត្រូវបានប្រតិបត្តិជាលំដាប់លំដោយ (Sequentially) ។ នៅពេលអ្នកដំណើរការ Command (Command) មួយ ដូចជា `mvn install` Maven នឹងប្រតិបត្តិដំណាក់កាលទាំងអស់រហូតដល់ `install` ។ ដំណាក់កាលសំខាន់ៗរួមមាន៖

*   **`validate`**: ផ្ទៀងផ្ទាត់ (Validate) ថាគម្រោងត្រឹមត្រូវ និងព័ត៌មានចាំបាច់ទាំងអស់អាចរកបាន។
*   **`compile`**: Compile (Compile) កូដប្រភពរបស់គម្រោង។
*   **`test`**: ដំណើរការ Tests (Tests) សម្រាប់គម្រោងដោយប្រើ Framework (Framework) ដែលសមរម្យ (ឧទាហរណ៍ JUnit) ។
*   **`package`**: ខ្ចប់ (Package) កូដដែលបាន Compile (Compiled Code) ទៅជាទម្រង់ដែលអាចចែកចាយបាន (Distributable Format) ដូចជា JAR (JAR) ឬ WAR (WAR) ។
*   **`verify`**: ដំណើរការការត្រួតពិនិត្យ (Checks) ដើម្បីផ្ទៀងផ្ទាត់គុណភាពនៃ Package ។
*   **`install`**: ដំឡើង Package ទៅក្នុង Local Repository (Local Repository) របស់ Maven ដែលអនុញ្ញាតឲ្យគម្រោងផ្សេងទៀតនៅលើម៉ាស៊ីនតែមួយអាចប្រើវាជា Dependency (Dependency) ។
*   **`deploy`**: ចម្លង Package ចុងក្រោយទៅកាន់ Remote Repository (Remote Repository) សម្រាប់ការចែករំលែកជាមួយ Developers (Developers) និងគម្រោងផ្សេងទៀត។
*   **`clean`**: លុបឯកសារដែលបានបង្កើតពីការបង្កើត (Build) ពីមុន។

**ឧទាហរណ៍**: នៅពេលអ្នកវាយ `mvn package` Maven នឹងដំណើរការ `validate`, `compile`, `test` ហើយចុងក្រោយ `package` ។

### ៣. Commands ទូទៅរបស់ Maven (Common Maven Commands)

នេះគឺជា Commands មួយចំនួនដែលអ្នកនឹងប្រើជាញឹកញាប់ជាមួយ Maven:

*   **`mvn clean`**:
    *   **គោលបំណង**: លុបថត `target` ដែលផ្ទុកឯកសារដែលបានបង្កើតពី Build (Build) ពីមុន។
    *   **ពេលប្រើ**: មុនពេលចាប់ផ្តើម Build ថ្មី ដើម្បីធានាថាគ្មានឯកសារចាស់ៗដែលនៅសេសសល់។

*   **`mvn compile`**:
    *   **គោលបំណង**: Compile កូដប្រភព Java ទៅជា Bytecode (Bytecode) ។
    *   **ពេលប្រើ**: ដើម្បីពិនិត្យមើល Syntax (Syntax) របស់កូដ និងធានាថាវាអាច Compile បានត្រឹមត្រូវ។

*   **`mvn test`**:
    *   **គោលបំណង**: ដំណើរការ Test Unit (Unit Tests) ទាំងអស់របស់គម្រោង។
    *   **ពេលប្រើ**: ដើម្បីធានាថាការផ្លាស់ប្តូរកូដរបស់អ្នកមិនបានបំពានមុខងារដែលមានស្រាប់។

*   **`mvn package`**:
    *   **គោលបំណង**: Compile កូដ, ដំណើរការ Test, និងខ្ចប់គម្រោងទៅជា JAR (JAR) ឬ WAR (WAR) file នៅក្នុងថត `target` ។
    *   **ពេលប្រើ**: ដើម្បីបង្កើត Executable (Executable) របស់កម្មវិធី។

*   **`mvn install`**:
    *   **គោលបំណង**: ដំណើរការ `package` រួចហើយដំឡើង Package ទៅក្នុង Local Maven Repository របស់អ្នក។
    *   **ពេលប្រើ**: នៅពេលគម្រោងរបស់អ្នកជា Dependency សម្រាប់គម្រោង Local ផ្សេងទៀត។

*   **`mvn spring-boot:run`**:
    *   **គោលបំណង**: ដំណើរការកម្មវិធី Spring Boot ដោយផ្ទាល់ពី Maven ។
    *   **ពេលប្រើ**: សម្រាប់ការអភិវឌ្ឍន៍ និងសាកល្បងយ៉ាងឆាប់រហ័ស។

*   **`mvn dependency:tree`**:
    *   **គោលបំណង**: បង្ហាញពី Dependencies ទាំងអស់របស់គម្រោងក្នុងទម្រង់ជា Tree (Tree) ។
    *   **ពេលប្រើ**: សម្រាប់ការបំបាត់កំហុស (Debugging) បញ្ហា Dependency ។

ការយល់ដឹងអំពី Maven និង Commands របស់វាគឺជាជំនាញដ៏សំខាន់សម្រាប់ Developers (Developers) Spring Boot គ្រប់រូប។

### ៤. ការបន្ថែម Custom Dependency (Custom Dependency) ទៅក្នុង `pom.xml`

ដើម្បីបន្ថែម Dependency ណាមួយទៅក្នុងគម្រោង Maven របស់អ្នក អ្នកត្រូវកែប្រែឯកសារ `pom.xml` ដោយដាក់ព័ត៌មានលម្អិតនៃ Dependency នោះនៅក្នុង `<dependencies>` block ។

**រចនាសម្ព័ន្ធទូទៅនៃ Dependency (General Structure of a Dependency):**

```xml
<dependency>
    <groupId>...</groupId>
    <artifactId>...</artifactId>
    <version>...</version>
    <scope>...</scope> <!-- ស្រេចចិត្ត (Optional) -->
</dependency>
```

**ការពន្យល់អំពី Elements (Elements) នីមួយៗ:**

*   **`<groupId>`**: កំណត់អត្តសញ្ញាណតែមួយគត់សម្រាប់គម្រោងដែលបង្កើត Dependency នេះ។ ជាធម្មតាវាជាឈ្មោះ Domain (Domain Name) បញ្ច្រាស ដូចជា `com.example` ឬ `org.apache.commons` ។
*   **`<artifactId>`**: កំណត់អត្តសញ្ញាណតែមួយគត់សម្រាប់ Project (Project) នៅក្នុង Group (Group) ។ ឧទាហរណ៍ `spring-boot-starter-web` ឬ `commons-lang3` ។
*   **`<version>`**: កំណត់កំណែជាក់លាក់នៃ Dependency ដែលអ្នកចង់ប្រើ។ ការប្រើប្រាស់កំណែជាក់លាក់ជួយធានានូវភាពស៊ីសង្វាក់គ្នា (Consistency) ក្នុងការបង្កើត។
*   **`<scope>` (ស្រេចចិត្ត - Optional)**: កំណត់វិសាលភាព (Scope) នៃ Dependency ។ នេះបញ្ជាក់ថាពេលណា Dependency នោះគួរតែមាននៅក្នុង Classpath (Classpath) ។
    *   `compile` (លំនាំដើម): Dependency មានសម្រាប់ Compile (Compile), Test (Test) និង Runtime (Runtime) ។
    *   `runtime`: Dependency ត្រូវការសម្រាប់ Runtime ប៉ុន្តែមិនមែនសម្រាប់ Compile ទេ។ ឧទាហរណ៍ Driver (Driver) សម្រាប់មូលដ្ឋានទិន្នន័យ។
    *   `test`: Dependency ត្រូវការសម្រាប់ Compile និង Run Test ប៉ុន្តែមិនមែនសម្រាប់ Runtime ទេ។ ឧទាហរណ៍ JUnit ។
    *   `provided`: Dependency ត្រូវការសម្រាប់ Compile និង Test ប៉ុន្តែត្រូវបានផ្តល់ជូនដោយ Runtime Environment (Runtime Environment) (ឧទាហរណ៍ Servlet API នៅក្នុង Application Server) ។

**ឧទាហរណ៍៖ ការបន្ថែម `Apache Commons Lang` Dependency**

ឧបមាថាអ្នកចង់ប្រើបណ្ណាល័យ `Apache Commons Lang` ដើម្បីទទួលបានមុខងារងាយស្រួលសម្រាប់ការគ្រប់គ្រង Strings (Strings) ឬ Arrays (Arrays) ។ អ្នកនឹងបន្ថែមវាទៅក្នុង `pom.xml` របស់អ្នកដូចខាងក្រោម៖

1.  **បើកឯកសារ `pom.xml`**:
    *   ស្វែងរក `<dependencies>` block របស់គម្រោងអ្នក។

2.  **បន្ថែម Dependency ខាងក្រោម (Add the following Dependency)**:

```xml
    <dependencies>
        <!-- Dependencies ដែលមានស្រាប់របស់អ្នក -->

        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-lang3</artifactId>
            <version>3.12.0</version>
        </dependency>

    </dependencies>
```

3.  **Reload Maven Project (Reload Maven Project)**:
    *   បន្ទាប់ពីបន្ថែម Dependency ថ្មី សូមរកមើល Icon (Icon) 'Load Maven Changes' នៅក្នុង IDE របស់អ្នក ហើយចុចវា។ IDE នឹងទាញយកបណ្ណាល័យ `commons-lang3` ហើយធ្វើឲ្យវាអាចប្រើបានក្នុងគម្រោងរបស់អ្នក។

ដោយធ្វើតាមជំហានទាំងនេះ អ្នកអាចបន្ថែម Dependencies ផ្សេងៗទៀតទៅក្នុងគម្រោង Spring Boot របស់អ្នកបានយ៉ាងងាយស្រួល។

### ៥. ឧទាហរណ៍ជាក់ស្តែងនៃ Build Lifecycle ជាមួយ Plugin (Practical Example of Build Lifecycle with Plugin)

តាមធម្មតា Maven មានដំណាក់កាល (Phases) ស្តង់ដារ ប៉ុន្តែយើងអាចបន្ថែមមុខងារពិសេសទៅកាន់ដំណាក់កាលទាំងនោះបានតាមរយៈការកំណត់រចនាសម្ព័ន្ធ **Plugins** ។

**ករណីសិក្សា៖ ការបង្កើត Executable JAR ស្វ័យប្រវត្តិ**

នៅក្នុង Spring Boot ឯកសារ `pom.xml` តែងតែមាន `spring-boot-maven-plugin` ។ Plugin នេះត្រូវបានកំណត់ឱ្យដំណើរការនៅដំណាក់កាល `package` ដើម្បីបំប្លែង JAR ធម្មតាឱ្យទៅជា Executable JAR (JAR ដែលអាច Run បាន) ។

**ជំហាននៃដំណើរការ (Step-by-Step Flow):**

1.  **ការកំណត់ក្នុង `pom.xml`**:
```xml
<build>
    <plugins>
        <plugin>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-maven-plugin</artifactId>
            <executions>
                <execution>
                    <goals>
                        <goal>repackage</goal>
                    </goals>
                </execution>
            </executions>
        </plugin>
    </plugins>
</build>
```

2.  **នៅពេលអ្នកដំណើរការ Command `mvn package`**:
    *   **Phase: `compile`** -> Maven បកប្រែកូដ `.java` ទៅជា `.class` ។
    *   **Phase: `test`** -> Maven ដំណើរការ Unit Tests ទាំងអស់។
    *   **Phase: `package`** -> 
        *   ដំបូង Maven បង្កើត JAR ធម្មតាមួយ (Standard JAR) ។
        *   បន្ទាប់មក `spring-boot-maven-plugin` នឹងចាប់ផ្តើមធ្វើការ (Execution) ដើម្បី **Repackage** JAR នោះ ដោយបន្ថែមបណ្ណាល័យ (Dependencies) និង Embedded Server ទៅខាងក្នុង។

3.  **លទ្ធផលចុងក្រោយ**:
    *   អ្នកនឹងទទួលបានឯកសារនៅក្នុងថត `target/` ឈ្មោះ `demo-0.0.1-SNAPSHOT.jar` ដែលអ្នកអាចយកទៅ Run នៅលើ Server ណាទ្បើយបានដោយគ្រាន់តែប្រើបញ្ជា `java -jar filename.jar` ។

នេះបង្ហាញថា Maven Build Lifecycle មិនត្រឹមតែដំណើរការតាមលំដាប់លំដោយប៉ុណ្ណោះទេ ប៉ុន្តែវាថែមទាំងអនុញ្ញាតឱ្យ Plugins ចូលទៅជួយបំពេញភារកិច្ចបន្ថែមក្នុងដំណាក់កាលនីមួយៗបានយ៉ាងឆ្លាតវៃ។