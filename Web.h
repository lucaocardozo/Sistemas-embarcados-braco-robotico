const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="UTF-8">
    <style>
      h1 {
        font-family: 'Arial', sans-serif;
        font-size: 24px;
        text-align: center;
        background: #f2f2f2;
        display: inline-block;
        padding: 10px;
        border-radius: 5px;
        box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        color: #333;
      }

      body {
        margin: 0;
        padding: 0;
        text-align: center;
        color: #555;
        background: #f9f9f9;
      }

      label {
        display: block;
        margin-top: 20px;
        font-size: 16px;
      }

      input {
        width: 60%;
        padding: 10px;
        border: 2px solid #ddd;
        border-radius: 4px;
        font-size: 14px;
        color: #333;
      }

      input:focus {
        outline: none;
        border-color: #888;
      }

      .value {
        display: inline-block;
        width: 40px;
        text-align: center;
      }

      .arrow {
        display: inline-block;
        width: 20px;
        height: 20px;
        cursor: pointer;
        border: 1px solid black;
        text-align: center;
        line-height: 20px;
        margin-right: 5px;
        position: relative;
        z-index: 2;
        vertical-align: middle;
        margin-top: 20px;
      }

      .open-button,
      .close-button {
        display: inline-block;
        width: 50px;
        height: 20px;
        cursor: pointer;
        border: 1px solid black;
        text-align: center;
        line-height: 18px;
        margin-left: 5px;
        margin-right: 5px;
        position: relative;
        z-index: 2;
        vertical-align: middle;
        margin-top: 20px;
      }

      .button-container {
        display: flex;
        align-items: center;
        justify-content: center;
        margin-top: 20px;
      }

      .button-container .arrow {
        margin-right: 0;
        margin-left: 5px;
      }

      .button-container:first-child .arrow {
        margin-left: 0;
      }

      .button-container label {
        margin-left: 10px;
        margin-right: 10px;
      }

      .button-container:last-child .arrow {
        margin-right: 0;
      }

      .slidecontainer {
        text-align: center;
      }
</style>
  </head>
  <body>



<h1>TCC2 - Lucas Martins Cardozo</h1>
<br><br>
<div class="container">
  <div class="leftside wfxc">
    <div class="slidecontainer">
      <div class="button-container">
        <span id="decrement1" class="arrow">&lt;</span>
        <label>&nbsp;Rotação&nbsp;</label>
        <span id="increment1" class="arrow">&gt;</span>
      </div>
      <div>
        <input type="range" min="0" max="180" value="90" id="myRange">
        <span id="value1" class="value"></span>
      </div>
    </div>
    
    <div class="slidecontainer">
      <div class="button-container">
        <span id="openButton" class="open-button">Abrir</span>
        <label>&nbsp;Garra&nbsp;</label>
        <span id="closeButton" class="close-button">Fechar</span>
      </div>
      <div>
        <input type="range" min="0" max="180" value="90" id="myRange1">
        <span id="value2" class="value"></span>
      </div>
    </div>
  </div>
  <div class="rightside wfxc">
    <div class="slidecontainer">
      <div class="button-container">
        <span id="decrement3" class="arrow">&lt;</span>
        <label>&nbsp;Baixo - Cima&nbsp;</label>
        <span id="increment3" class="arrow">&gt;</span>
      </div>
      <div>
        <input type="range" min="0" max="180" value="90" id="myRange2"/>
        <span id="value3" class="value"></span>
      </div>
    </div>
    
    <div class="slidecontainer">
      <div class="button-container">
        <span id="decrement4" class="arrow">&lt;</span>
        <label>Trás - Frente</label>
        <span id="increment4" class="arrow">&gt;</span>
      </div>
      <div>
        <input type="range" min="0" max="180" value="90" id="myRange3"/>
        <span id="value4" class="value"></span>
      </div>
    </div>
  </div>
</div>


<script>
  function sendData(pos1, pos2, pos3, pos4) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        console.log(this.responseText);
      }
    };
    xhttp.open("GET", "setPOS?POS1=" + pos1 + "&POS2=" + pos2 + "&POS3=" + pos3 + "&POS4=" + pos4, true);
    xhttp.send();
  } 

  var s1 = 90;
  var s2 = 90;
  var s3 = 90;
  var s4 = 90;

  var value1 = document.getElementById("value1");
  var value2 = document.getElementById("value2");
  var value3 = document.getElementById("value3");
  var value4 = document.getElementById("value4");

  // Atualiza os valores iniciais
  value1.textContent = s1 + "°";
  value2.textContent = s2 + "°";
  value3.textContent = s3 + "°";
  value4.textContent = s4 + "°";

  var slider1 = document.getElementById("myRange");
  var slider2 = document.getElementById("myRange1");
  var slider3 = document.getElementById("myRange2");
  var slider4 = document.getElementById("myRange3");

  slider1.oninput = function() {
    s1 = slider1.value;
    value1.textContent = s1 + "°"; // Atualiza o valor exibido
    sendData(s1, s2, s3, s4); // Envia os valores para processamento
  }
  slider2.oninput = function() {
    s2 = slider2.value;
    value2.textContent = s2 + "°"; // Atualiza o valor exibido
    sendData(s1, s2, s3, s4); // Envia os valores para processamento
  }
  slider3.oninput = function() {
    s3 = slider3.value;
    value3.textContent = s3 + "°"; // Atualiza o valor exibido
    sendData(s1, s2, s3, s4); // Envia os valores para processamento
  }
  slider4.oninput = function() {
    s4 = slider4.value;
    value4.textContent = s4 + "°"; // Atualiza o valor exibido
    sendData(s1, s2, s3, s4); // Envia os valores para processamento
  }

  // Incremento e decremento ao clicar nas setas
  var increment1 = document.getElementById("increment1");
  var decrement1 = document.getElementById("decrement1");
  var increment3 = document.getElementById("increment3");
  var decrement3 = document.getElementById("decrement3");
  var increment4 = document.getElementById("increment4");
  var decrement4 = document.getElementById("decrement4");

  increment1.onclick = function() {
    s1 = parseInt(s1) + 10;
    if (s1 > 180) s1 = 180;
    slider1.value = s1;
    value1.textContent = s1 + "°";
    sendData(s1, s2, s3, s4);
  }

  decrement1.onclick = function() {
    s1 = parseInt(s1) - 10;
    if (s1 < 0) s1 = 0;
    slider1.value = s1;
    value1.textContent = s1 + "°";
    sendData(s1, s2, s3, s4);
  }

  increment3.onclick = function() {
    s3 = parseInt(s3) + 10;
    if (s3 > 180) s3 = 180;
    slider3.value = s3;
    value3.textContent = s3 + "°";
    sendData(s1, s2, s3, s4);
  }

  decrement3.onclick = function() {
    s3 = parseInt(s3) - 10;
    if (s3 < 0) s3 = 0;
    slider3.value = s3;
    value3.textContent = s3 + "°";
    sendData(s1, s2, s3, s4);
  }

  increment4.onclick = function() {
    s4 = parseInt(s4) + 10;
    if (s4 > 180) s4 = 180;
    slider4.value = s4;
    value4.textContent = s4 + "°";
    sendData(s1, s2, s3, s4);
  }

  decrement4.onclick = function() {
    s4 = parseInt(s4) - 10;
    if (s4 < 0) s4 = 0;
    slider4.value = s4;
    value4.textContent = s4 + "°";
    sendData(s1, s2, s3, s4);
  }

  // Botões de abrir e fechar
  var openButton = document.getElementById("openButton");
  var closeButton = document.getElementById("closeButton");

  openButton.onclick = function() {
    s2 = 0;
    slider2.value = s2;
    value2.textContent = s2 + "°";
    sendData(s1, s2, s3, s4);
  }

  closeButton.onclick = function() {
    s2 = 180;
    slider2.value = s2;
    value2.textContent = s2 + "°";
    sendData(s1, s2, s3, s4);
  }
</script>

  </body>
</html>
)=====";
