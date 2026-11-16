# JSX EXPLAINED

### With Examples

JSX (JavaScript XML) is a syntax extension for JavaScript that lets you write HTML-like code in your React components.

### 1. What is JSX?

JSX look like HTML, but it's actually JavaScript. It allows you to write UI directly inside your JavaScript code, making React components more readable and easy to manage.

``` javascript
const element = (
    <dive className = "card">
        <h1>Welcome</h1>
        <p>JSX makes React simple!</p>
    </div>
);
```

**Example**

#### Functional Component

A simple React component using JSX.

``` javascript
function Greeting(){
    return(
        <div className="greeting">
            <h2>Hellow, React!</H2>
            <p>Welcome to JSX</p>
        </div>
    );
}
```

