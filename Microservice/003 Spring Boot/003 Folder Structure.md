## ផ្នែកទី៣៖ ការស្វែងយល់ពីរចនាសម្ព័ន្ធថត (Folder Structure) និងឯកសារ (pom.xml / application.properties)

នៅពេលដែលអ្នកបានបង្កើតគម្រោង Spring Boot ដោយប្រើ Spring Initializr ហើយបាននាំចូល (Import) វាទៅក្នុង IDE (IDE) របស់អ្នក អ្នកនឹងឃើញរចនាសម្ព័ន្ធថត (Folder Structure) ស្តង់ដារមួយ។ ការយល់ដឹងពីរចនាសម្ព័ន្ធនេះគឺសំខាន់ណាស់សម្រាប់ការរៀបចំកូដ (Organizing Code) និងការកំណត់រចនាសម្ព័ន្ធ (Configuration) គម្រោងរបស់អ្នក។

### ១. រចនាសម្ព័ន្ធថតមូលដ្ឋាន (Basic Folder Structure)

នេះគឺជារចនាសម្ព័ន្ធថតគម្រោង Spring Boot ជាទូទៅ៖

```
myfirstapp
├── .mvn
│   ├── wrapper
│       ├── maven-wrapper.jar
│       └── maven-wrapper.properties
├── src
│   ├── main
│   │   ├── java
│   │   │   └── com
│   │   │       └── example
│   │   │           └── demo
│   │   │               └── DemoApplication.java
│   │   └── resources
│   │       ├── application.properties
│   │       ├── static
│   │       ├── templates
│   │       └── banner.txt
│   └── test
│       └── java
│           └── com
│               └── example
│                   └── demo
│                       └── DemoApplicationTests.java
├── .gitignore
├── mvnw
├── mvnw.cmd
├── pom.xml
└── README.md
```

**ការពន្យល់អំពីថត និងឯកសារសំខាន់ៗ:**

*   `myfirstapp/` (ថតគម្រោងឫស - Root Project Folder): ថតមេដែលផ្ទុកឯកសារ និងថតទាំងអស់របស់គម្រោង។
*   `.mvn/`: ផ្ទុកឯកសារ Maven Wrapper (Maven Wrapper) ដែលអនុញ្ញាតឲ្យអ្នករាល់គ្នាបង្កើតគម្រោងដោយប្រើកំណែ Maven ដូចគ្នា ទោះបីជាពួកគេមិនបានដំឡើង Maven ជាក់លាក់ក៏ដោយ។
*   `src/`: ថតប្រភព (Source Folder) ។ វាមានពីរថតសំខាន់គឺ `main` និង `test` ។
    *   `src/main/`: ផ្ទុកកូដប្រភព (Source Code) និងធនធាន (Resources) របស់កម្មវិធី។
        *   `src/main/java/`: នេះជាកន្លែងដែលកូដ Java (Java Code) ទាំងអស់របស់អ្នកស្ថិតនៅ។ តាមអនុសញ្ញា (Convention) វាត្រូវបានបែងចែកជា Package (Package) តាមឈ្មោះ Group (Group Name) ដែលអ្នកបានកំណត់នៅក្នុង Spring Initializr (ឧទាហរណ៍ `com.example.demo`) ។
            *   `DemoApplication.java`: ជា Class (Class) ចម្បង (Main Class) សម្រាប់កម្មវិធី Spring Boot របស់អ្នក។ វាផ្ទុកវិធីសាស្ត្រ `main()` ដែលដំណើរការកម្មវិធី។
        *   `src/main/resources/`: ថតនេះសម្រាប់ដាក់ឯកសារធនធាន (Resource Files) ដូចជា៖
            *   `application.properties` (ឬ `application.yml`): ឯកសារកំណត់រចនាសម្ព័ន្ធសំខាន់ (Main Configuration File) សម្រាប់ Spring Boot ។
            *   `static/`: សម្រាប់ឯកសារ Static Web Content (Static Web Content) ដូចជា HTML, CSS, JavaScript និងរូបភាព។
            *   `templates/`: សម្រាប់ឯកសារ Template (Template Files) ដូចជា Thymeleaf, FreeMarker ។
            *   `banner.txt`: សម្រាប់បន្ថែម Banner (Banner) ផ្ទាល់ខ្លួននៅពេលកម្មវិធីចាប់ផ្តើម (Application Startup) ។
    *   `src/test/`: ផ្ទុកកូដតេស្ត (Test Code) សម្រាប់កម្មវិធីរបស់អ្នក។
*   `.gitignore`: ឯកសារដែលកំណត់ថាឯកសារ ឬថតណាខ្លះដែល Git (Git) គួរតែមិនអើពើ (Ignore) ពេល Commit (Commit) ទៅកាន់ Repository (Repository) ។
*   `mvnw`, `mvnw.cmd`: Maven Wrapper Script (Maven Wrapper Script) សម្រាប់ Linux/macOS និង Windows រៀងគ្នា។
*   `README.md`: ឯកសារ README (README File) ដែលជាទូទៅមានការពិពណ៌នាអំពីគម្រោង និងរបៀបដំណើរការវា។

### ២. ការយល់ដឹងអំពីឯកសារ `pom.xml`

ដូចដែលបានពន្យល់ពីមុន `pom.xml` គឺជាបេះដូងនៃគម្រោង Maven ។ នេះជាឧទាហរណ៍ខ្លះៗនៃអ្វីដែលអ្នកនឹងឃើញនៅក្នុងវា៖

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
	<modelVersion>4.0.0</modelVersion>
	<parent>
		<groupId>org.springframework.boot</groupId>
		<artifactId>spring-boot-starter-parent</artifactId>
		<version>3.2.5</version>
		<relativePath/> <!-- lookup parent from repository -->
	</parent>
	<groupId>com.example</groupId>
	<artifactId>demo</artifactId>
	<version>0.0.1-SNAPSHOT</version>
	<name>demo</name>
	<description>Demo project for Spring Boot</description>
	<properties>
		<java.version>17</java.version>
	</properties>
	<dependencies>
		<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-web</artifactId>
		</dependency>

		<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-devtools</artifactId>
			<scope>runtime</scope>
			<optional>true</optional>
		</dependency>
		<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-test</artifactId>
			<scope>test</scope>
		</dependency>
	</dependencies>

	<build>
		<plugins>
			<plugin>
				<groupId>org.springframework.boot</groupId>
				<artifactId>spring-boot-maven-plugin</artifactId>
			</plugin>
		</plugins>
	</build>

</project>
```

**ចំណុចសំខាន់ៗដែលត្រូវចំណាំ:**

*   `<parent>`: កំណត់ `<spring-boot-starter-parent>` ជា Parent POM (Parent POM) ។ នេះផ្តល់នូវការកំណត់រចនាសម្ព័ន្ធលំនាំដើម (Default Configurations) ដ៏មានប្រយោជន៍ និងការគ្រប់គ្រងកំណែ (Version Management) សម្រាប់ dependencies ជាច្រើន។
*   `<groupId>`, `<artifactId>`, `<version>`: កំណត់អត្តសញ្ញាណតែមួយគត់សម្រាប់គម្រោងរបស់អ្នក។
*   `<properties>`: កន្លែងសម្រាប់កំណត់ Global Properties (Global Properties) ដូចជាកំណែ Java (Java Version) ។
*   `<dependencies>`: នេះជាកន្លែងដែលអ្នកប្រកាសបណ្ណាល័យ (Libraries) ទាំងអស់ដែលគម្រោងរបស់អ្នកត្រូវការ។ ឧទាហរណ៍៖
    *   `spring-boot-starter-web`: ផ្តល់នូវ dependencies សំខាន់ៗសម្រាប់ការអភិវឌ្ឍន៍ Web (Web Development) រួមទាំង Tomcat (Tomcat) ដែលបានបង្កប់។
    *   `spring-boot-devtools`: ផ្តល់នូវមុខងារ Development-time (Development-time Features) ដូចជា Live Reload (Live Reload) ។
*   `<build>`: កន្លែងសម្រាប់កំណត់រចនាសម្ព័ន្ធ Build plugins (Build Plugins) ។ `<spring-boot-maven-plugin>` គឺចាំបាច់សម្រាប់ការបង្កើត Executable JAR (Executable JAR) ។

### ៣. ឯកសារ `application.properties` (ឬ `application.yml`)

ឯកសារ `application.properties` ដែលស្ថិតនៅក្នុងថត `src/main/resources` គឺជាឯកសារកំណត់រចនាសម្ព័ន្ធសំខាន់សម្រាប់ Spring Boot ។ វានៅទីនេះដែលអ្នកកំណត់លក្ខណសម្បត្តិ (Properties) សម្រាប់កម្មវិធីរបស់អ្នក ដូចជា:

*   **Server Port (Server Port)**: កំណត់ Port ដែល Web Server (Web Server) នឹងដំណើរការ (លំនាំដើមគឺ 8080) ។
    ```properties
    server.port=8081
    ```
*   **Database Connection (Database Connection)**: កំណត់ព័ត៌មានលម្អិតសម្រាប់ការតភ្ជាប់ទៅកាន់មូលដ្ឋានទិន្នន័យ (Database) ។
    ```properties
    spring.datasource.url=jdbc:h2:mem:testdb
    spring.datasource.username=sa
    spring.datasource.password=
    spring.datasource.driver-class-name=org.h2.Driver
    ```
*   **Logging Levels (Logging Levels)**: កំណត់កម្រិត Logging (Logging Level) សម្រាប់ Package (Package) ឬ Class (Class) ជាក់លាក់។
    ```properties
    logging.level.root=INFO
    logging.level.org.springframework=DEBUG
    ```
*   **Application Name (Application Name)**:
    ```properties
    spring.application.name=my-spring-boot-app
    ```

អ្នកក៏អាចប្រើ `application.yml` ជំនួស `application.properties` បានដែរ។ ឯកសារ `.yml` ប្រើទម្រង់ YAML (YAML Format) ដែលមានលក្ខណៈងាយស្រួលអានជាងសម្រាប់លក្ខណសម្បត្តិស្មុគស្មាញ (Complex Properties) ។

ឧទាហរណ៍ `application.yml` សម្រាប់ Port និង Database:

```yaml
server:
  port: 8081
spring:
  datasource:
    url: jdbc:h2:mem:testdb
    username: sa
    password: ''
    driver-class-name: org.h2.Driver
```

ការយល់ដឹងពីឯកសារទាំងពីរនេះគឺចាំបាច់សម្រាប់ការអភិវឌ្ឍន៍ Spring Boot ប្រកបដោយប្រសិទ្ធភាព។