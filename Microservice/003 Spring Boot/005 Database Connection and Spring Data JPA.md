## ផ្នែកទី៥៖ ការភ្ជាប់ទៅកាន់មូលដ្ឋានទិន្នន័យ (Database Connection) ជាមួយ Spring Data JPA

នៅក្នុងផ្នែកនេះ យើងនឹងរៀនពីរបៀបភ្ជាប់កម្មវិធី Spring Boot របស់យើងទៅកាន់មូលដ្ឋានទិន្នន័យ (Database) ដោយប្រើប្រាស់ Spring Data JPA (Spring Data JPA) ។ Spring Data JPA ធ្វើឲ្យការធ្វើអន្តរកម្មជាមួយមូលដ្ឋានទិន្នន័យ (Database Interaction) មានភាពងាយស្រួលដោយផ្តល់នូវAbstraction (Abstraction) មួយពី JDBC (JDBC) និងORM (ORM) ដូចជា Hibernate (Hibernate) ។

សម្រាប់ឧទាហរណ៍នេះ យើងនឹងប្រើប្រាស់ H2 Database (H2 Database) ដែលជាមូលដ្ឋានទិន្នន័យ In-memory (In-memory Database) ដែលងាយស្រួលប្រើសម្រាប់ Development (Development) និង Testing (Testing) ។

### ១. ការបន្ថែម Dependencies សម្រាប់ Database (Adding Database Dependencies)

ដំបូង យើងត្រូវបន្ថែម Dependencies (Dependencies) ដែលចាំបាច់ទៅក្នុងឯកសារ `pom.xml` របស់យើង។

1.  **បើកឯកសារ `pom.xml`**:
    *   ស្វែងរក `<dependencies>` block ។

2.  **បន្ថែម Dependencies ខាងក្រោម (Add the following Dependencies)**:

```xml
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-jpa</artifactId>
        </dependency>
        <dependency>
            <groupId>com.h2database</groupId>
            <artifactId>h2</artifactId>
            <scope>runtime</scope>
        </dependency>
```

*   **`spring-boot-starter-data-jpa`**: នេះគឺជា Starter (Starter) ដែលផ្តល់នូវអ្វីគ្រប់យ៉ាងដែលអ្នកត្រូវការដើម្បីប្រើប្រាស់ Spring Data JPA រួមទាំង Hibernate (ដែលជា ORM (ORM) លំនាំដើម) ។
*   **`h2`**: នេះគឺជា Driver (Driver) សម្រាប់ H2 Database ។ យើងដាក់ `scope` ជា `runtime` ព្រោះយើងមិនត្រូវការវាសម្រាប់ការ Compile-time (Compile-time) ទេ។

3.  **Reload Maven Project (Reload Maven Project)**:
    *   បន្ទាប់ពីកែប្រែ `pom.xml` សូមរកមើល Icon (Icon) 'Load Maven Changes' (ជាធម្មតាជារូបសញ្ញា Maven ឬសញ្ញា Refresh) នៅក្នុង IDE របស់អ្នក ហើយចុចវា។ នេះនឹងទាញយក Dependencies ថ្មីៗ។

### ២. ការកំណត់រចនាសម្ព័ន្ធ H2 Database (Configuring H2 Database)

យើងនឹងកំណត់រចនាសម្ព័ន្ធ H2 Database នៅក្នុងឯកសារ `application.properties` (ឬ `application.yml`) ។

1.  **បើក `src/main/resources/application.properties`**:

2.  **បន្ថែមការកំណត់រចនាសម្ព័ន្ធខាងក្រោម (Add the following Configuration)**:

```properties
# H2 Database Configuration
spring.h2.console.enabled=true
spring.h2.console.path=/h2-console
spring.datasource.url=jdbc:h2:mem:testdb
spring.datasource.driverClassName=org.h2.Driver
spring.datasource.username=sa
spring.datasource.password=
spring.jpa.database-platform=org.hibernate.dialect.H2Dialect
spring.jpa.hibernate.ddl-auto=update

# Logging for SQL statements (optional)
logging.level.org.hibernate.SQL=DEBUG
logging.level.org.hibernate.type.descriptor.sql.BasicBinder=TRACE
```

**ការពន្យល់អំពី Properties (Properties) ទាំងនេះ:**

*   `spring.h2.console.enabled=true`: បើក H2 Console (H2 Console) ដែលជា Web UI (Web UI) សម្រាប់គ្រប់គ្រង H2 Database ។
*   `spring.h2.console.path=/h2-console`: កំណត់ Path (Path) សម្រាប់ចូលទៅកាន់ H2 Console (ឧទាហរណ៍ `http://localhost:8080/h2-console`) ។
*   `spring.datasource.url=jdbc:h2:mem:testdb`: កំណត់ URL (URL) របស់មូលដ្ឋានទិន្នន័យ។ `jdbc:h2:mem:testdb` មានន័យថាយើងកំពុងប្រើ In-memory H2 Database ដែលនឹងត្រូវបានបង្កើត និងបំផ្លាញរាល់ពេលដែលកម្មវិធីចាប់ផ្តើម។ `testdb` គឺជាឈ្មោះមូលដ្ឋានទិន្នន័យ។
*   `spring.datasource.driverClassName=org.h2.Driver`: កំណត់ Driver Class (Driver Class) សម្រាប់ H2 Database ។
*   `spring.datasource.username=sa`: កំណត់ Username (Username) សម្រាប់ចូលទៅមូលដ្ឋានទិន្នន័យ (លំនាំដើមសម្រាប់ H2) ។
*   `spring.datasource.password=`: កំណត់ Password (Password) (ទុកចោលព្រោះ H2 In-memory មិនត្រូវការ Password) ។
*   `spring.jpa.database-platform=org.hibernate.dialect.H2Dialect`: ប្រាប់ Hibernate (Hibernate) ថាវាគួរតែប្រើ SQL Dialect (SQL Dialect) សម្រាប់ H2 Database ។
*   `spring.jpa.hibernate.ddl-auto=update`: នេះគឺជា Property (Property) សំខាន់មួយរបស់ Hibernate ។
    *   `update`: Hibernate នឹងព្យាយាមកែប្រែ Schema (Schema) របស់មូលដ្ឋានទិន្នន័យដើម្បីផ្គូផ្គង Entity (Entity) របស់អ្នក។ វានឹងបង្កើតតារាង (Tables) ថ្មីៗ ជួរឈរ (Columns) ថ្មីៗ និងកែប្រែដែលមានស្រាប់ ប៉ុន្តែវានឹងមិនលុបតារាង ឬទិន្នន័យឡើយ។
    *   សម្រាប់ Development និង Testing ជម្រើស `update` ឬ `create` គឺមានប្រយោជន៍។ សម្រាប់ Production (Production) អ្នកគួរតែប្រើ `none` ហើយគ្រប់គ្រង Schema ដោយដៃ (Manually) ឬដោយ Migration Tools (Migration Tools) ។

*   `logging.level.org.hibernate.SQL=DEBUG` និង `logging.level.org.hibernate.type.descriptor.sql.BasicBinder=TRACE`: ទាំងនេះគឺជា Logging Properties (Logging Properties) ដែលនឹងបង្ហាញ SQL Query (SQL Queries) ដែលត្រូវបានប្រតិបត្តិដោយ Hibernate នៅក្នុង Console (Console) ។ មានប្រយោជន៍សម្រាប់ការ Debugging (Debugging) ។

### ៣. ការបង្កើត Entity Class (Creating an Entity Class)

Entity (Entity) គឺជា Class Java (Java Class) ដែលតំណាងឲ្យតារាង (Table) មួយនៅក្នុងមូលដ្ឋានទិន្នន័យរបស់អ្នក។

1.  **បង្កើត Package ថ្មី (Create a New Package)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo` បង្កើត Package ថ្មីមួយដែលមានឈ្មោះថា `model` ។

2.  **បង្កើត Class `Product` (Create `Product` Class)**:
    *   នៅក្នុង Package `model` សូមបង្កើត Class Java ថ្មីមួយដែលមានឈ្មោះថា `Product.java` ។

3.  **សរសេរកូដសម្រាប់ Entity Class (Write Code for the Entity Class)**:

```java
package com.example.demo.model;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity
public class Product {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String name;
    private double price;

    public Product() {
    }

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    // Getters and Setters
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Product{" +
               "id=" + id +
               ", name='" + name + '\'' +
               ", price=" + price +
               '}';
    }
}
```

**ការពន្យល់អំពី Annotations (Annotations) នៅក្នុង Entity Class:**

*   **`@Entity`**: បញ្ជាក់ថា Class នេះគឺជា Entity ដែលតំណាងឲ្យតារាងមួយនៅក្នុងមូលដ្ឋានទិន្នន័យ។
*   **`@Id`**: បញ្ជាក់ថា Field (Field) `id` គឺជា Primary Key (Primary Key) របស់ Entity នេះ។
*   **`@GeneratedValue(strategy = GenerationType.IDENTITY)`**: កំណត់ថា Primary Key `id` នឹងត្រូវបានបង្កើតដោយស្វ័យប្រវត្តិដោយមូលដ្ឋានទិន្នន័យ (Auto-increment)។
*   `name` និង `price`: ទាំងនេះនឹងក្លាយជា Columns (Columns) នៅក្នុងតារាង `product` ។
*   `public Product()`: Constructor (Constructor) លំនាំដើម (Default) គឺចាំបាច់សម្រាប់ JPA (JPA) ។
*   `Getters` និង `Setters`: ប្រើសម្រាប់ចូលប្រើ និងកែប្រែទិន្នន័យរបស់ Fields ។
*   `toString()`: សម្រាប់បោះពុម្ព (Printing) Object (Object) ក្នុងទម្រង់ងាយស្រួលអានសម្រាប់ការ Debugging ។

### ៤. ការបង្កើត Repository Interface (Creating a Repository Interface)

Spring Data JPA ផ្តល់នូវ Abstraction (Abstraction) ដ៏មានឥទ្ធិពលមួយដែលមានឈ្មោះថា Repository (Repository) ។ Repository Interface (Repository Interface) ជួយឲ្យយើងធ្វើអន្តរកម្មជាមួយមូលដ្ឋានទិន្នន័យដោយមិនចាំបាច់សរសេរកូដ SQL (SQL Code) ច្រើន។

1.  **បង្កើត Package ថ្មី (Create a New Package)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo` បង្កើត Package ថ្មីមួយដែលមានឈ្មោះថា `repository` ។

2.  **បង្កើត Interface `ProductRepository` (Create `ProductRepository` Interface)**:
    *   នៅក្នុង Package `repository` សូមបង្កើត Interface Java ថ្មីមួយដែលមានឈ្មោះថា `ProductRepository.java` ។

3.  **សរសេរកូដសម្រាប់ Repository Interface (Write Code for the Repository Interface)**:

```java
package com.example.demo.repository;

import com.example.demo.model.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ProductRepository extends JpaRepository<Product, Long> {
}
```

**ការពន្យល់អំពីកូដខាងលើ:**

*   **`@Repository`**: Annotation នេះបញ្ជាក់ថា Interface នេះជា Spring Bean (Spring Bean) ដែលទទួលខុសត្រូវក្នុងការគ្រប់គ្រង Persistence Layer (Persistence Layer) ។
*   **`extends JpaRepository<Product, Long>`**: នេះជាចំណុចសំខាន់។ ដោយគ្រាន់តែ Extend (Extend) Interface `JpaRepository` យើងទទួលបានវិធីសាស្ត្រ CRUD (CRUD Methods) ជាច្រើនដោយស្វ័យប្រវត្តិ (ឧទាហរណ៍៖ `save()`, `findAll()`, `findById()`, `delete()`) ។
    *   `Product`: គឺជា Entity Type (Entity Type) ដែល Repository នេះនឹងធ្វើការជាមួយ។
    *   `Long`: គឺជា Type (Type) នៃ Primary Key (Primary Key) របស់ Entity `Product` (ក្នុងករណីរបស់យើងគឺ `id`) ។

ឥឡូវនេះ អ្នកបានកំណត់រចនាសម្ព័ន្ធមូលដ្ឋានទិន្នន័យ H2 (H2 Database), បានបង្កើត Entity (Entity) និង Repository (Repository) សម្រាប់ធ្វើអន្តរកម្មជាមួយមូលដ្ឋានទិន្នន័យហើយ។

### ៥. ការបង្កើត REST Controller សម្រាប់ Product (Creating a REST Controller for Product)

ឥឡូវនេះយើងមាន Entity (Entity) និង Repository (Repository) ហើយ យើងត្រូវការ Controller (Controller) ដើម្បីបង្ហាញ (Expose) CRUD Operations (CRUD Operations) ទាំងនេះជា REST Endpoints (REST Endpoints) ។

1.  **បង្កើត Class `ProductController` (Create `ProductController` Class)**:
    *   នៅក្នុងថត `src/main/java/com/example/demo/controller` សូមបង្កើត Class Java ថ្មីមួយដែលមានឈ្មោះថា `ProductController.java` ។

2.  **សរសេរកូដសម្រាប់ Product Controller (Write Code for the Product Controller)**:

```java
package com.example.demo.controller;

import com.example.demo.model.Product;
import com.example.demo.repository.ProductRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/api/products")
public class ProductController {

    @Autowired
    private ProductRepository productRepository;

    // Create a new Product
    @PostMapping
    public ResponseEntity<Product> createProduct(@RequestBody Product product) {
        Product savedProduct = productRepository.save(product);
        return new ResponseEntity<>(savedProduct, HttpStatus.CREATED);
    }

    // Get all Products
    @GetMapping
    public ResponseEntity<List<Product>> getAllProducts() {
        List<Product> products = productRepository.findAll();
        return new ResponseEntity<>(products, HttpStatus.OK);
    }

    // Get a Product by ID
    @GetMapping("/{id}")
    public ResponseEntity<Product> getProductById(@PathVariable Long id) {
        Optional<Product> product = productRepository.findById(id);
        return product.map(value -> new ResponseEntity<>(value, HttpStatus.OK))
                       .orElseGet(() -> new ResponseEntity<>(HttpStatus.NOT_FOUND));
    }

    // Update a Product
    @PutMapping("/{id}")
    public ResponseEntity<Product> updateProduct(@PathVariable Long id, @RequestBody Product productDetails) {
        Optional<Product> product = productRepository.findById(id);
        if (product.isPresent()) {
            Product existingProduct = product.get();
            existingProduct.setName(productDetails.getName());
            existingProduct.setPrice(productDetails.getPrice());
            Product updatedProduct = productRepository.save(existingProduct);
            return new ResponseEntity<>(updatedProduct, HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }

    // Delete a Product
    @DeleteMapping("/{id}")
    public ResponseEntity<HttpStatus> deleteProduct(@PathVariable Long id) {
        try {
            productRepository.deleteById(id);
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } catch (Exception e) {
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
}
```

**ការពន្យល់អំពី Annotations និង Methods (Explanation of Annotations and Methods):**

*   **`@RestController`**: ដូចដែលបានពន្យល់ពីមុន បញ្ជាក់ថា Class នេះជា Controller ដែលដោះស្រាយសំណើ RESTful (RESTful Requests) ។
*   **`@RequestMapping("/api/products")`**: កំណត់ Base Path (Base Path) សម្រាប់ Endpoints (Endpoints) ទាំងអស់នៅក្នុង Controller នេះ។ រាល់ Endpoint នឹងចាប់ផ្តើមដោយ `/api/products` ។
*   **`@Autowired`**: Annotation នេះប្រើសម្រាប់ចាក់បញ្ចូល (Inject) Dependency (Dependency) ។ នៅទីនេះ Spring (Spring) នឹងបង្កើត Instance (Instance) របស់ `ProductRepository` ហើយចាក់វាទៅក្នុង `productRepository` Field (Field) ដោយស្វ័យប្រវត្តិ។
*   **`@PostMapping`** (`createProduct`) :
    *   ដោះស្រាយសំណើ HTTP POST (HTTP POST Requests) ទៅកាន់ `/api/products` ។
    *   **`@RequestBody Product product`**: បង្ហាញថា Object `Product` នឹងត្រូវបានទទួលពី Request Body (Request Body) (ជាធម្មតាជាទម្រង់ JSON) ។ Spring Boot នឹងបម្លែង JSON ទៅជា Object `Product` ។
    *   `productRepository.save(product)`: នេះគឺជាវិធីសាស្ត្រដែលបានផ្តល់ដោយ `JpaRepository` ដើម្បីរក្សាទុក (Save) Object `Product` ទៅក្នុងមូលដ្ឋានទិន្នន័យ។ ប្រសិនបើ `product` មាន `id` វានឹងធ្វើការ Update (Update) ហើយប្រសិនបើគ្មាន `id` វានឹងធ្វើការ Create (Create) ។
    *   `ResponseEntity`: ផ្តល់នូវការគ្រប់គ្រងពេញលេញលើ HTTP Response (HTTP Response) រួមទាំង Status Code (Status Code) (ឧទាហរណ៍ `CREATED` - 201) ។
*   **`@GetMapping`** (`getAllProducts`) :
    *   ដោះស្រាយសំណើ HTTP GET (HTTP GET Requests) ទៅកាន់ `/api/products` ។
    *   `productRepository.findAll()`: វិធីសាស្ត្រនេះត្រឡប់បញ្ជី (List) នៃ `Product` ទាំងអស់ពីមូលដ្ឋានទិន្នន័យ។
*   **`@GetMapping("/{id}")`** (`getProductById`) :
    *   ដោះស្រាយសំណើ HTTP GET (HTTP GET Requests) ទៅកាន់ `/api/products/{id}` ។
    *   **`@PathVariable Long id`**: ទាញយកតម្លៃ `id` ពី URL Path (URL Path) ។
    *   `productRepository.findById(id)`: វិធីសាស្ត្រនេះត្រឡប់ `Optional<Product>` ។ `Optional` ត្រូវបានប្រើដើម្បីដោះស្រាយករណីដែល Object អាចមាន (Present) ឬអត់ (Not Present) ។
*   **`@PutMapping("/{id}")`** (`updateProduct`) :
    *   ដោះស្រាយសំណើ HTTP PUT (HTTP PUT Requests) ទៅកាន់ `/api/products/{id}` សម្រាប់ការ Update ។
    *   វាស្វែងរក Product ដែលមានស្រាប់ បន្ទាប់មក Update ព័ត៌មានរបស់វា ហើយរក្សាទុក (Save) វិញ។
*   **`@DeleteMapping("/{id}")`** (`deleteProduct`) :
    *   ដោះស្រាយសំណើ HTTP DELETE (HTTP DELETE Requests) ទៅកាន់ `/api/products/{id}` សម្រាប់ការលុប។
    *   `productRepository.deleteById(id)`: វិធីសាស្ត្រនេះលុប Entity ដោយប្រើ Primary Key (Primary Key) របស់វា។

### ៦. ការសាកល្បង REST API Endpoints (Testing REST API Endpoints)

ដើម្បីសាកល្បង Endpoints ទាំងនេះ អ្នកត្រូវដំណើរការកម្មវិធី Spring Boot របស់អ្នកជាមុនសិន។ បន្ទាប់មកអ្នកអាចប្រើឧបករណ៍ដូចជា **Postman**, **Insomnia** ឬ **`curl` command-line tool** ។

**ជំហានក្នុងការដំណើរការកម្មវិធី:**

1.  **ដំណើរការកម្មវិធី Spring Boot (Run the Spring Boot Application)**:
    *   ដូចពីមុន សូមដំណើរការ Class `DemoApplication.java` នៅក្នុង IDE របស់អ្នក។
    *   ត្រូវប្រាកដថាអ្នកឃើញសារដែលបង្ហាញថា Tomcat (Tomcat) កំពុងដំណើរការនៅលើ Port 8080 (ឬ Port ដែលអ្នកបានកំណត់) ។

**ឧទាហរណ៍ការសាកល្បងដោយប្រើ `curl` (Test Examples using `curl`):**

**(ក) បង្កើត Product ថ្មី (Create a New Product - POST)**

```bash
curl -X POST http://localhost:8080/api/products \ 
-H "Content-Type: application/json" \ 
-d '{"name": "Laptop", "price": 1200.00}'
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 201 Created រួមជាមួយនឹង Object Product (Product Object) ដែលបានបង្កើត រួមទាំង `id` របស់វា។
    ```json
    {"id":1,"name":"Laptop","price":1200.0}
    ```

**(ខ) បង្កើត Product មួយទៀត (Create Another Product)**

```bash
curl -X POST http://localhost:8080/api/products \ 
-H "Content-Type: application/json" \ 
-d '{"name": "Mouse", "price": 25.50}'
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 201 Created រួមជាមួយនឹង Object Product ដែលបានបង្កើត (ឧទាហរណ៍ `id:2`) ។

**(គ) ទទួលបាន Products ទាំងអស់ (Get All Products - GET)**

```bash
curl http://localhost:8080/api/products
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 200 OK រួមជាមួយនឹងបញ្ជី (List) នៃ Products ទាំងអស់ជា JSON (JSON Array) ។
    ```json
    [{"id":1,"name":"Laptop","price":1200.0},{"id":2,"name":"Mouse","price":25.5}]
    ```

**(ឃ) ទទួលបាន Product តាម ID (Get Product by ID - GET)**

```bash
curl http://localhost:8080/api/products/1
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 200 OK រួមជាមួយនឹង Product ដែលមាន `id` 1 ។
    ```json
    {"id":1,"name":"Laptop","price":1200.0}
    ```
*   ប្រសិនបើ ID មិនមាន (e.g., `http://localhost:8080/api/products/99`) អ្នកនឹងទទួលបាន HTTP Status 404 Not Found (404 Not Found) ។

**(ង) Update Product (Update Product - PUT)**

```bash
curl -X PUT http://localhost:8080/api/products/1 \ 
-H "Content-Type: application/json" \ 
-d '{"name": "Gaming Laptop", "price": 1500.00}'
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 200 OK រួមជាមួយនឹង Product ដែលបាន Update រួច។
    ```json
    {"id":1,"name":"Gaming Laptop","price":1500.0}
    ```

**(ច) លុប Product (Delete Product - DELETE)**

```bash
curl -X DELETE http://localhost:8080/api/products/2
```

*   **រំពឹងថាទទួលបាន (Expected Response)**: HTTP Status 204 No Content (204 No Content) ។

អ្នកបានបង្កើត និងសាកល្បង CRUD REST API (CRUD REST API) របស់អ្នកដោយជោគជ័យហើយ! នេះគឺជាមូលដ្ឋានគ្រឹះសម្រាប់ការកសាងកម្មវិធី Back-end (Back-end Applications) ជាមួយ Spring Boot និង Spring Data JPA ។
