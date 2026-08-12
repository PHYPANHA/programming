## ផ្នែកទី៧៖ ការអនុវត្តន៍ JWT Authentication (JWT Authentication) ជំនួស HTTP Basic

JWT (JSON Web Tokens) គឺជាស្តង់ដារមួយដែលប្រើសម្រាប់បង្កើត Access Tokens (Access Tokens) ដែលអនុញ្ញាតឲ្យអ្នកប្រើប្រាស់ផ្ទៀងផ្ទាត់ (Authenticate) ខ្លួនឯងជាមួយ Server (Server) ។ វាមិនរក្សាទុកស្ថានភាព (Stateless) ដែលធ្វើឲ្យវាស័ក្តិសមសម្រាប់ REST APIs (REST APIs) និង Microservices (Microservices) ។

### ១. ការបន្ថែម Dependencies សម្រាប់ JWT (Adding JWT Dependencies)

យើងត្រូវបន្ថែមបណ្ណាល័យ (Library) `jjwt` សម្រាប់ការបង្កើត និងផ្ទៀងផ្ទាត់ JWTs ។

1.  **បើកឯកសារ `pom.xml`**:
    *   ស្វែងរក `<dependencies>` block ។

2.  **បន្ថែម Dependency ខាងក្រោម (Add the following Dependency)**:

```xml
        <dependency>
            <groupId>io.jsonwebtoken</groupId>
            <artifactId>jjwt-api</artifactId>
            <version>0.11.5</version>
        </dependency>
        <dependency>
            <groupId>io.jsonwebtoken</groupId>
            <artifactId>jjwt-impl</artifactId>
            <version>0.11.5</version>
            <scope>runtime</scope>
        </dependency>
        <dependency>
            <groupId>io.jsonwebtoken</groupId>
            <artifactId>jjwt-jackson</artifactId>
            <version>0.11.5</version>
            <scope>runtime</scope>
        </dependency>
```

*   **ចំណាំ**: សូមប្រាកដថាអ្នកប្រើប្រាស់កំណែ (Version) ស្របគ្នាសម្រាប់ `jjwt-api`, `jjwt-impl`, និង `jjwt-jackson` ។

3.  **Reload Maven Project (Reload Maven Project)**:
    *   បន្ទាប់ពីកែប្រែ `pom.xml` សូមរកមើល Icon (Icon) 'Load Maven Changes' នៅក្នុង IDE របស់អ្នក ហើយចុចវា។ នេះនឹងទាញយក Dependencies ថ្មីៗ។

### ២. ការបង្កើត JWT Utility Class (Creating a JWT Utility Class)

យើងនឹងបង្កើត Class មួយដើម្បីដោះស្រាយការបង្កើត (Generating) ការផ្ទៀងផ្ទាត់ (Validating) និងការទាញយកព័ត៌មាន (Extracting Information) ពី JWT Tokens ។

1.  **បង្កើត Package ថ្មី (Create a New Package)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo` បង្កើត Package ថ្មីមួយដែលមានឈ្មោះថា `jwt` ។

2.  **បង្កើត Class `JwtUtil` (Create `JwtUtil` Class)**:
    *   នៅក្នុង Package `jwt` សូមបង្កើត Class Java ថ្មីមួយដែលមានឈ្មោះថា `JwtUtil.java` ។

3.  **សរសេរកូដសម្រាប់ JWT Utility (Write Code for the JWT Utility)**:

```java
package com.example.demo.jwt;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import io.jsonwebtoken.io.Decoders;
import io.jsonwebtoken.security.Keys;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.stereotype.Component;

import java.security.Key;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

@Component
public class JwtUtil {

    @Value("${jwt.secret}")
    private String SECRET_KEY;

    public String extractUsername(String token) {
        return extractClaim(token, Claims::getSubject);
    }

    public Date extractExpiration(String token) {
        return extractClaim(token, Claims::getExpiration);
    }

    public <T> T extractClaim(String token, Function<Claims, T> claimsResolver) {
        final Claims claims = extractAllClaims(token);
        return claimsResolver.apply(claims);
    }

    private Claims extractAllClaims(String token) {
        return Jwts.parserBuilder().setSigningKey(getSignKey()).build().parseClaimsJws(token).getBody();
    }

    private Boolean isTokenExpired(String token) {
        return extractExpiration(token).before(new Date());
    }

    public String generateToken(UserDetails userDetails) {
        Map<String, Object> claims = new HashMap<>();
        return createToken(claims, userDetails.getUsername());
    }

    private String createToken(Map<String, Object> claims, String subject) {
        return Jwts.builder()
                .setClaims(claims)
                .setSubject(subject)
                .setIssuedAt(new Date(System.currentTimeMillis()))
                .setExpiration(new Date(System.currentTimeMillis() + 1000 * 60 * 60 * 10)) // 10 hours validity
                .signWith(getSignKey(), SignatureAlgorithm.HS256)
                .compact();
    }

    public Boolean validateToken(String token, UserDetails userDetails) {
        final String username = extractUsername(token);
        return (username.equals(userDetails.getUsername()) && !isTokenExpired(token));
    }

    private Key getSignKey() {
        byte[] keyBytes = Decoders.BASE64.decode(SECRET_KEY);
        return Keys.hmacShaKeyFor(keyBytes);
    }
}
```

4.  **បន្ថែម `jwt.secret` ទៅ `application.properties` (Add `jwt.secret` to `application.properties`)**:
    *   យើងត្រូវការ Secret Key (Secret Key) សម្រាប់ចុះហត្ថលេខា (Signing) និងផ្ទៀងផ្ទាត់ (Verifying) JWT Tokens ។ បន្ថែមវាទៅក្នុង `src/main/resources/application.properties` ។ សូមប្រើ String (String) ដែលវែង និងស្មុគស្មាញ (Complex) ។ អ្នកអាចបង្កើតវាដោយប្រើ Online Generator (Online Generator) ។

    ```properties
    jwt.secret=yourVerySecretKeyThatShouldBeLongAndComplexAndStoredSecurelyAndNeverHardcodedInProduction
    ```

