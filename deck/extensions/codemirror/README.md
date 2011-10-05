Deck.js-CodeMirror Extension
============================

This extension allows you to embed codemirror code snippets in your slides. Those codeblocks
can also be executable, which is pretty exciting.

An example is running here: http://ireneros.com/deck/deck.js-codemirror/introduction

You can also see those slides in the `introduction` folder.

# Installation: #

Move all this into a folder called 'codemirror' in your deck.js/extensions/ folder.

# Setup: #

Include the stylesheet:

    <link rel="stylesheet" href="../extensions/codemirror/deck.codemirror.css">

Include the JS source:

    <!-- Base codemiror code -->
    <script src="../extensions/codemirror/codemirror.js"></script>

    <!-- Syntax highlighting Modes -->
    
    <!-- javascript -->
    <script src="../mode/javascript/javascript.js"></script>

    <!-- html mode (note html mode requires xml, css and javascript) -->
    <script src="../extensions/codemirror/mode/xml/xml.js"></script>
    <script src="../extensions/codemirror/mode/css/css.js"></script>
    <script src="../extensions/codemirror/mode/htmlmixed/htmlmixed.js"></script>

    <!-- Plugin code -->
    <script src="../extensions/codemirror/deck.codemirror.js"></script>

Include your favorite CodeMirror syntax style:

    <link rel="stylesheet" href="../extensions/codemirror/themes/default.css">

  Options are:
    
    cobalt.css
    default.css
    elegant.css
    neat.css
    night.css


# Use: #

There are two ways to create code blocks:
Inside your slide:

## Text Area:

    <div>
      <textarea id="code" name="code" class="code" mode="javascript" style="display: none;" runnable="true">// codemirror demo party!
        var greeter = function(name) {
          return "Why hello there " + name;
        }
        console.log(greeter("Joe"));
      </textarea>
    </div>
  
## Any other item:

    <div>
      <div id="code" name="code" class="code" mode="javascript" style="display: none;">// codemirror demo party!
        var obj = { text : "Hello all!"};
        console.log("HI THERE");
      </div>
    </div>

# Element Attributes: #

Regardless of your element type, the following attributes should be set:

* class - code (should always be set to code.)
* mode  - language mode. This plugin now supports all modes. Look into the mode directory and include the ones you like. Note that some require additional modes so be sure to check the Codemirror site.
* theme (optional) - If you want multiple themes in your slides, include multiple stylesheets and set this attribute to the theme name.
* runnable (optiona) - If true, will add a Run button to the window and pipe the eval's console output to an output element right below. 

# Contact: #
Irene Ros (@ireneros)
http://bocoup.com

    
