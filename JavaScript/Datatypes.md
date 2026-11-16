## Explained Visually

JavaScript has different data types to store different kinds of values. Everything in JavaScript is a value, and every value has a data type.

### 1. String

Represents text or characters.

``` javascript
let name = "Parvez";
let message = 'Hello!;
```

``` javascript
Hello!
```

### 2. Number

Represents numberic values (integers or decimals).

``` Javascript
let age = 25;
let price = 99.99;
```

``` javascript
25
```

### 3. BigInt

Represents very large integers beyon the safe limit of Number.

``` javascript
let id = 1234567890123n;
```

### 4. Boolean

Represents a logical value (true or false).

``` javascript
let isActive = true;
let isLoggedIn = false;
```

### 5. Underfined 

A variable that has been declared but not assigned a value.
``` javascript
let x;
```

### 6. Null

Represents the intentional absence of any value.

``` javascript
let user = null;
```

### 7. Object

Represents a collection of key-value pairs.

``` javascript
let user = {
    name: "Parvez",
    age: 25
}
```

``` javascript
{key:value}
```

### 8. Array
 Represents an ordered collection of valeus.

 ``` javascript
 let fruits = ["Apple","Banana","Mango"];
 ```

 ``` javascript
 Apple
 Banana
 Mango
 ```

 ### 9. Symbol

 Represents a unique and immulatable value (usually used as object keys).

 ``` javascript
 let id = Symbol("id");
 ```
 
 ### 10. Function

 A special type of object that can be called to perform a task.

 ``` javascript
 functiongreet(){
    console.log("Hello!");
 }
 ```

 ### 11. DAate

 Represents a date and time value.

 ``` javascript
 let today = new Date();
 ```

 ### 12. RegExp

 Represents a regular expression for pattern matching.

 ``` javascript
 let pattern = /hello/i;
 ```
 