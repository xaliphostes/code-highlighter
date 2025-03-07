# Code Highlighter
Code Highlighter is a JavaScript library that makes it easy to display and syntax highlight code snippets on your web pages.

## [Doc in HTML](https://xaliphostes.github.io/code-highlighter/)

## Example
See this [**file**](example.html) where a cpp code is rendered from a file, and the other one is written in the html code.

It provides two main components:

## CodeFromFile
A custom HTML element that loads code from external files and applies syntax highlighting.

### Attributes

The `<code-from-file>` element supports the following attributes:

| Attribute | Description | Required | Default | Example |
|-----------|-------------|----------|---------|---------|
| `src` | Path to the code file to load | Yes | - | `src="./code/example.js"` |
| `language` | Programming language for syntax highlighting | No | Auto-detected from file extension | `language="cpp"` |
| `highlight-lines` | Line numbers to highlight | No | None | `highlight-lines="5-10,12"` |

### Line Highlighting Syntax

The `highlight-lines` attribute accepts a comma-separated list of line numbers or ranges:

- Single line: `highlight-lines="5"`
- Multiple lines: `highlight-lines="5,7,9"`
- Line range: `highlight-lines="5-10"`
- Mix of single lines and ranges: `highlight-lines="3,5-10,15,20-25"`

### Custom Styling

The component uses Shadow DOM to encapsulate its styles, but you can customize the appearance by targeting the custom element in your CSS:

```css
/* Increase size of all code blocks */
code-from-file {
  font-size: 16px;
  margin: 20px 0;
  display: block;
}

/* Add a border */
code-from-file::part(container) {
  border: 1px solid #ddd;
  border-radius: 4px;
}
```

### Basic Usage

To display code from an external file, simply use the `<code-from-file>` tag with the `src` attribute pointing to your code file:

```html
<code-from-file src="./path/to/example.js"></code-from-file>
```

### With Line Highlighting

Highlight specific lines to draw attention to them:

```html
<h2>Important Code Section</h2>
<code-from-file 
  src="./code/algorithm.cpp" 
  language="cpp" 
  highlight-lines="15-20,25">
</code-from-file>
```

## CodeBlockManager
A utility that manages inline code blocks defined within script tags in your HTML.

### Attributes Reference

When defining code blocks with script tags, you can use these attributes:

| Attribute         | Description                                                 | Example                   |
| ----------------- | ----------------------------------------------------------- | ------------------------- |
| `type`            | Required. Must start with "code-block"                      | `type="code-block"`       |
| `language`        | The programming language for syntax highlighting            | `language="cpp"`          |
| `target`          | ID of the element where the code should be rendered         | `target="example1"`       |
| `highlight-lines` | Line numbers to highlight (comma-separated, ranges allowed) | `highlight-lines="1,3-5"` |
| `id`              | Optional custom ID for the code block                       | `id="my-special-code"`    |

### Line Highlighting Syntax

The `highlight-lines` attribute accepts a comma-separated list of line numbers or ranges:

- Single line: `highlight-lines="5"`
- Multiple lines: `highlight-lines="5,7,9"`
- Line range: `highlight-lines="5-10"`
- Mix of single lines and ranges: `highlight-lines="3,5-10,15,20-25"`

### Custom Styling

You can add custom CSS to style your code blocks:

```css
.code-container {
    margin: 20px 0;
    border-radius: 8px;
    overflow: hidden;
}

.code-container pre {
    margin: 0;
    padding: 16px;
    background-color: #f6f8fa;
}

.line-highlight {
    background-color: rgba(255, 235, 59, 0.2) !important;
}
```

### Basic Usage

#### Method 1: Using Script Tags

The simplest way to define code blocks is to use `<script>` tags with the `type="code-block"` attribute:

```html
<script type="code-block" language="cpp" target="example1">
class MyClass {
public:
    MyClass() = default;
    void doSomething();
};
</script>

<!-- This is where the code will be rendered -->
<div id="example1"></div>
```

#### Method 2: Using the JavaScript API

You can also add code blocks programmatically:

```javascript
// Register a code block
const id = codeBlockManager.registerBlock(`
function hello() {
    console.log("Hello, world!");
}
`, {
    language: "javascript",
    elementId: "hello-example"
});

// Render all code blocks
codeBlockManager.renderAll();
```

#### With Line Highlighting

```html
<script type="code-block" language="cpp" target="cpp-example" highlight-lines="2,5-7">
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    
    return 0;
}
</script>

<div id="cpp-example"></div>