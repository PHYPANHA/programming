## ផ្នែកទី៦៖ ការបន្ថែមសុវត្ថិភាព (Security) ទៅកាន់ REST Endpoints ជាមួយ Spring Security

ការការពារ REST Endpoints (REST Endpoints) របស់អ្នកគឺមានសារៈសំខាន់ណាស់ ដើម្បីធានាថាមានតែអ្នកប្រើប្រាស់ដែលមានការអនុញ្ញាត (Authorized Users) ប៉ុណ្ណោះដែលអាចចូលប្រើទិន្នន័យ និងមុខងាររបស់កម្មវិធីអ្នក។ Spring Security (Spring Security) គឺជាក្របខ័ណ្ឌការងារ (Framework) ដ៏មានឥទ្ធិពល និងអាចបត់បែនបាន (Highly Customizable) សម្រាប់ផ្តល់សុវត្ថិភាពដល់កម្មវិធី Spring (Spring Applications)។

### ១. ការបន្ថែម Spring Security Dependency (Adding Spring Security Dependency)

ដំបូង យើងត្រូវបន្ថែម Spring Security Starter (Spring Security Starter) ទៅក្នុងឯកសារ `pom.xml` របស់យើង។

1.  **បើកឯកសារ `pom.xml`**:
    *   ស្វែងរក `<dependencies>` block ។

2.  **បន្ថែម Dependency ខាងក្រោម (Add the following Dependency)**:

```xml
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-security</artifactId>
        </dependency>
```

3.  **Reload Maven Project (Reload Maven Project)**:
    *   បន្ទាប់ពីកែប្រែ `pom.xml` សូមរកមើល Icon (Icon) 'Load Maven Changes' នៅក្នុង IDE របស់អ្នក ហើយចុចវា។ នេះនឹងទាញយក Dependency ថ្មីៗ។

### ២. ការបង្កើត Security Configuration Class (Creating a Security Configuration Class)

បន្ទាប់មក យើងត្រូវបង្កើត Class (Class) សម្រាប់កំណត់រចនាសម្ព័ន្ធ Spring Security ។ នេះជាកន្លែងដែលយើងកំណត់ច្បាប់ (Rules) សម្រាប់ Authentication (Authentication) និង Authorization (Authorization) ។

1.  **បង្កើត Package ថ្មី (Create a New Package)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo` បង្កើត Package ថ្មីមួយដែលមានឈ្មោះថា `security` ។

2.  **បង្កើត Class `SecurityConfig` (Create `SecurityConfig` Class)**:
    *   នៅក្នុង Package `security` សូមបង្កើត Class Java ថ្មីមួយដែលមានឈ្មោះថា `SecurityConfig.java` ។

3.  **សរសេរកូដសម្រាប់ Security Configuration (Write Code for the Security Configuration)**:

```java
package com.example.demo.security;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
@EnableWebSecurity
public class SecurityConfig {

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .csrf(csrf -> csrf.disable()) // Disable CSRF for simplicity in REST APIs, consider enabling for web apps
            .authorizeHttpRequests(authorize -> authorize
                .requestMatchers("/h2-console/**").permitAll() // Allow access to H2 console
                .requestMatchers("/api/products/**").authenticated() // Secure all product endpoints
                .anyRequest().authenticated() // All other requests need authentication
            )
            .httpBasic(org.springframework.security.config.Customizer.withDefaults()); // Use HTTP Basic authentication
        
        // Required for H2 console to work with Spring Security
        http.headers(headers -> headers.frameOptions(frameOptions -> frameOptions.sameOrigin()));

        return http.build();
    }

    @Bean
    public UserDetailsService userDetailsService() {
        UserDetails user = User.withDefaultPasswordEncoder()
            .username("user")
            .password("password")
            .roles("USER")
            .build();
        return new InMemoryUserDetailsManager(user);
    }
}
```

### ៣. ការពន្យល់អំពី Security Configuration (Explanation of Security Configuration)

*   **`@Configuration`**: បញ្ជាក់ថា Class នេះមាន Beans (Beans) ដែលកំណត់រចនាសម្ព័ន្ធ (Configuration Beans)។
*   **`@EnableWebSecurity`**: បើកដំណើរការ Web Security (Web Security) របស់ Spring Security ។
*   **`securityFilterChain(HttpSecurity http)`**: នេះគឺជា Bean (Bean) សំខាន់ដែលកំណត់រចនាសម្ព័ន្ធ HTTP Security (HTTP Security) ។
    *   `csrf(csrf -> csrf.disable())`: យើងបិទ CSRF (Cross-Site Request Forgery) សម្រាប់ REST APIs (REST APIs) ដើម្បីងាយស្រួលក្នុងការធ្វើតេស្ត។ នៅក្នុង Web Applications (Web Applications) ដែលមាន Forms (Forms) អ្នកគួរតែបើកវា។
    *   `authorizeHttpRequests(...)`: កំណត់ច្បាប់ Authorization (Authorization) សម្រាប់សំណើ HTTP (HTTP Requests) ។
        *   `requestMatchers("/h2-console/**").permitAll()`: អនុញ្ញាតឲ្យចូលប្រើ H2 Console (H2 Console) ដោយគ្មានការផ្ទៀងផ្ទាត់ (Authentication) ។
        *   `requestMatchers("/api/products/**").authenticated()`: តម្រូវឲ្យមានការផ្ទៀងផ្ទាត់ (Authentication) សម្រាប់ Endpoint (Endpoints) ទាំងអស់ដែលចាប់ផ្តើមដោយ `/api/products/` ។
        *   `anyRequest().authenticated()`: តម្រូវឲ្យមានការផ្ទៀងផ្ទាត់សម្រាប់សំណើផ្សេងទៀតទាំងអស់។
    *   `httpBasic(Customizer.withDefaults())`: បើកដំណើរការ HTTP Basic Authentication (HTTP Basic Authentication) ។ នេះមានន័យថា Browser (Browser) ឬ Client (Client) នឹងសួររក Username (Username) និង Password (Password) ។
    *   `http.headers(headers -> headers.frameOptions(frameOptions -> frameOptions.sameOrigin()))`: នេះគឺចាំបាច់ដើម្បីអនុញ្ញាតឲ្យ H2 Console ដំណើរការបានត្រឹមត្រូវនៅក្នុង Frame (Frame) ។
*   **`userDetailsService()`**: នេះគឺជា Bean (Bean) ដែលកំណត់ព័ត៌មានលម្អិតអ្នកប្រើប្រាស់ (User Details) ។ សម្រាប់ឧទាហរណ៍នេះ យើងប្រើ `InMemoryUserDetailsManager` ដើម្បីបង្កើតអ្នកប្រើប្រាស់ (User) នៅក្នុង Memory (Memory)៖
    *   **Username**: `user`
    *   **Password**: `password` (Spring Security នឹង Encrypt (Encrypt) វាដោយស្វ័យប្រវត្តិ)។
    *   **Role**: `USER`

### ៤. ការសាកល្បង REST API Endpoints ដែលមានសុវត្ថិភាព (Testing Secured REST API Endpoints)

ឥឡូវនេះ ប្រសិនបើអ្នកព្យាយាមចូលប្រើ Endpoint (Endpoint) `/api/products` ដោយគ្មាន Username (Username) និង Password (Password) អ្នកនឹងទទួលបាន HTTP Status 401 Unauthorized (401 Unauthorized) ។

**ជំហានក្នុងការសាកល្បង:**

1.  **ដំណើរការកម្មវិធី Spring Boot (Run the Spring Boot Application)**:
    *   ដំណើរការ Class `DemoApplication.java` ម្តងទៀត។

2.  **សាកល្បងដោយគ្មាន Authentication (Test Without Authentication)**:
    *   បើក Web Browser (Web Browser) របស់អ្នក ហើយចូលទៅកាន់ `http://localhost:8080/api/products` ។ អ្នកនឹងឃើញប្រអប់មួយលោតឡើងសុំ Username និង Password ។ ប្រសិនបើអ្នកចុច Cancel (Cancel) អ្នកនឹងទទួលបាន 401 Unauthorized ។

3.  **សាកល្បងជាមួយ `curl` (Test with `curl`)**:
    *   អ្នកអាចប្រើ `curl` ជាមួយ Username និង Password ដូចខាងក្រោម៖

    **(ក) បង្កើត Product ថ្មី (Create a New Product - POST)**

    ```bash
    curl -u user:password -X POST http://localhost:8080/api/products \
    -H "Content-Type: application/json" \
    -d '{"name": "Secured Item", "price": 99.99}'
    ```

    **(ខ) ទទួលបាន Products ទាំងអស់ (Get All Products - GET)**

    ```bash
    curl -u user:password http://localhost:8080/api/products
    ```

    **(គ) ចូលប្រើ H2 Console (Access H2 Console)**
    *   បើក Browser (Browser) ទៅ `http://localhost:8080/h2-console` ។ វានឹងនៅតែអាចចូលប្រើបានដោយគ្មាន Authentication (Authentication) ដោយសារតែ `permitAll()` ដែលយើងបានកំណត់រចនាសម្ព័ន្ធ។

អ្នកបានបន្ថែម Spring Security ទៅក្នុងកម្មវិធីរបស់អ្នកដោយជោគជ័យហើយ! នេះគ្រាន់តែជាការចាប់ផ្តើមប៉ុណ្ណោះ Spring Security មានមុខងារជាច្រើនទៀតដូចជា OAuth2 (OAuth2), JWT (JWT) និង LDAP (LDAP) ប៉ុន្តែការកំណត់រចនាសម្ព័ន្ធមូលដ្ឋាននេះផ្តល់នូវមូលដ្ឋានគ្រឹះដ៏រឹងមាំមួយ។

