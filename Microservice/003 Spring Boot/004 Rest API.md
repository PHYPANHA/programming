## ផ្នែកទី៤៖ ការបង្កើត REST API ដំបូង (Hello World) និងការប្រើប្រាស់ Annotations

នៅក្នុងផ្នែកនេះ យើងនឹងរៀនពីរបៀបបង្កើត RESTful API (RESTful API) សាមញ្ញមួយនៅក្នុង Spring Boot ដើម្បីឆ្លើយតប (Respond) ទៅនឹងសំណើ (Requests) របស់ HTTP (HTTP) ។ យើងនឹងបង្កើត Endpoint (Endpoint) 'Hello World' ដំបូងរបស់យើង ហើយស្វែងយល់ពីរបៀបប្រើប្រាស់ Annotations (Annotations) សំខាន់ៗ។

### ១. ការបង្កើត Controller Class (Creating a Controller Class)

នៅក្នុង Spring Boot, Controller (Controller) គឺជា Class (Class) ដែលដោះស្រាយសំណើ HTTP (HTTP Requests) និងបញ្ជូនការឆ្លើយតប (Responses) ។

1.  **បង្កើត Package ថ្មី (Create a New Package)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo` បង្កើត Package ថ្មីមួយដែលមានឈ្មោះថា `controller` ។

2.  **បង្កើត Class `HelloController` (Create `HelloController` Class)**:
    *   នៅក្នុង Package `controller` ដែលអ្នកទើបតែបង្កើត សូមបង្កើត Class Java ថ្មីមួយដែលមានឈ្មោះថា `HelloController.java` ។

3.  **សរសេរកូដសម្រាប់ Controller (Write Code for the Controller)**:

```java
package com.example.demo.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/hello")
    public String hello() {
        return "Hello, Spring Boot!";
    }
}
```

### ២. ការពន្យល់អំពី Annotations សំខាន់ៗ (Explanation of Key Annotations)

នៅក្នុងកូដខាងលើ យើងបានប្រើ Annotations សំខាន់ៗពីរ៖

*   **`@RestController`**:
    *   **គោលបំណង (Purpose)**: Annotation នេះគឺជាការរួមបញ្ចូលគ្នារវាង `@Controller` និង `@ResponseBody` ។
        *   `@Controller`: បញ្ជាក់ថា Class នេះជា Controller ដែលដោះស្រាយសំណើ Web (Web Requests) ។
        *   `@ResponseBody`: បញ្ជាក់ថាតម្លៃត្រឡប់ (Return Value) នៃវិធីសាស្ត្រ (Method) គួរតែត្រូវបានចងភ្ជាប់ (Bound) ដោយផ្ទាល់ទៅនឹងតួការឆ្លើយតប Web (Web Response Body) ។ នេះមានន័យថា Spring នឹងបម្លែង `String` 

    `Hello, Spring Boot!` ទៅជាទម្រង់ JSON (JSON) ឬ Text (Text) ហើយផ្ញើវាត្រឡប់ទៅ Client (Client) វិញ។

*   **`@GetMapping("/hello")`**:
    *   **គោលបំណង (Purpose)**: Annotation នេះប្រើសម្រាប់កំណត់វិធីសាស្ត្រ (Method) មួយណាដែលគួរតែដោះស្រាយសំណើ HTTP GET (HTTP GET Request) ទៅកាន់ URL (URL) `/hello` ។
    *   នៅពេលដែល Client ផ្ញើសំណើ GET (GET Request) ទៅកាន់ `http://localhost:8080/hello` (ឬ Port ដែលអ្នកបានកំណត់) វិធីសាស្ត្រ `hello()` នឹងត្រូវបានប្រតិបត្តិ។

### ៣. របៀបដំណើរការកម្មវិធី និងសាកល្បង API (How to Run the Application and Test the API)

ដើម្បីសាកល្បង API (API) ដែលអ្នកទើបតែបង្កើត៖

1.  **ដំណើរការកម្មវិធី Spring Boot (Run the Spring Boot Application)**:
    *   នៅក្នុង IDE របស់អ្នក (ឧទាហរណ៍ IntelliJ IDEA) សូមស្វែងរក Class `DemoApplication.java` (ឬឈ្មោះ Class មេរបស់កម្មវិធីអ្នក)។
    *   ចុច Right-click លើ Class នោះ រួចជ្រើសរើស `Run 'DemoApplication.main()'` ។
    *   អ្នកនឹងឃើញ Output (Output) នៅក្នុង Console (Console) ដែលបង្ហាញថា Spring Boot កំពុងដំណើរការ និងបានចាប់ផ្តើម Web Server (Web Server) (ជាធម្មតាគឺ Tomcat) នៅលើ Port 8080 (ឬ Port ផ្សេងទៀតដែលអ្នកបានកំណត់នៅក្នុង `application.properties`) ។

    ```bash
    # ឧទាហរណ៍ Output នៅក្នុង Console
    2023-10-27T10:00:00.123+07:00  INFO 12345 --- [  main] com.example.demo.DemoApplication         : Starting DemoApplication using Java 17.0.8.1 with PID 12345 (...
    ... output lines ...
    2023-10-27T10:00:00.567+07:00  INFO 12345 --- [  main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat initialized with port(s): 8080 (http)
    ... output lines ...
    2023-10-27T10:00:01.987+07:00  INFO 12345 --- [  main] com.example.demo.DemoApplication         : Started DemoApplication in 3.456 seconds (process running for 4.567)
    ```

2.  **សាកល្បង Endpoint ដោយប្រើ Browser (Test the Endpoint using a Browser)**:
    *   បើក Web Browser (Web Browser) របស់អ្នក។
    *   វាយបញ្ចូល URL ខាងក្រោមទៅក្នុង Address Bar (Address Bar):
        `http://localhost:8080/hello`
    *   អ្នកគួរតែឃើញអក្សរ `Hello, Spring Boot!` បង្ហាញនៅក្នុង Browser ។

    ![Hello Spring Boot](https://i.imgur.com/k6lP0aE.png)

អ្នកបានបង្កើត និងសាកល្បង REST API ដំបូងរបស់អ្នកដោយជោគជ័យហើយ! នេះគឺជាជំហានដំបូងដ៏សំខាន់ក្នុងការកសាងកម្មវិធី Web (Web Applications) ដ៏ស្មុគស្មាញជាមួយ Spring Boot ។

