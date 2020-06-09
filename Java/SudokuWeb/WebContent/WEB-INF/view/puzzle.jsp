<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
	<% String difficulty = (String) request.getAttribute("difficulty"); %>
	<% String option = (String) request.getAttribute("option"); %>
	<% String problem = (String) request.getAttribute("problem"); %>
	<% String solution = (String) request.getAttribute("solution"); %>
<head>
  <meta charset="UTF-8">
  <title>Puzzle_<%=difficulty %>_<%=option %></title>
  <link rel="stylesheet" href ="/SudokuWeb/css/PuzzleStyle.css" />
  <script src="https://kit.fontawesome.com/214bbd63e6.js" crossorigin="anonymous"></script>
</head>
<body>
  <input type="hidden" id="solution" value="<%=solution%>">
  <input type="hidden" id="selected" value="T0">
  <input type="hidden" id="blue" value="">
  <header>
    <h1>Sudoku</h1>
    <a href = "./index.jsp" aria-label = "Home" class='home'><i class="fas fa-home" ></i> </a>
    <hr />
  </header>
  <table class='page'>
    <tr>
      <td rowspan="2" width="50%">
        <table border="2" class='sudoku'>
          <tr>
	          <td id="T0"></td>
			  <td id="T1"></td>
			  <td id="T2"></td>
			  <td id="T3"></td>
			  <td id="T4"></td>
			  <td id="T5"></td>
			  <td id="T6"></td>
			  <td id="T7"></td>
			  <td id="T8"></td>
		  </tr>
		  <tr>
			  <td id="T9"></td>
	          <td id="T10"></td>
			  <td id="T11"></td>
			  <td id="T12"></td>
			  <td id="T13"></td>
			  <td id="T14"></td>
			  <td id="T15"></td>
			  <td id="T16"></td>
			  <td id="T17"></td>
		  </tr>
		  <tr>
			  <td id="T18"></td>
			  <td id="T19"></td>
			  <td id="T20"></td>
			  <td id="T21"></td>
			  <td id="T22"></td>
			  <td id="T23"></td>
			  <td id="T24"></td>
			  <td id="T25"></td>
			  <td id="T26"></td>
		  </tr>
		  <tr>
			  <td id="T27"></td>
			  <td id="T28"></td>
			  <td id="T29"></td>
	          <td id="T30"></td>
			  <td id="T31"></td>
			  <td id="T32"></td>
			  <td id="T33"></td>
			  <td id="T34"></td>
			  <td id="T35"></td>
		  </tr>
		  <tr>
			  <td id="T36"></td>
			  <td id="T37"></td>
			  <td id="T38"></td>
			  <td id="T39"></td>
			  <td id="T40"></td>
			  <td id="T41"></td>
			  <td id="T42"></td>
			  <td id="T43"></td>
			  <td id="T44"></td>
		  </tr>
		  <tr>
			  <td id="T45"></td>
			  <td id="T46"></td>
			  <td id="T47"></td>
			  <td id="T48"></td>
			  <td id="T49"></td>
			  <td id="T50"></td>
			  <td id="T51"></td>
			  <td id="T52"></td>
			  <td id="T53"></td>
		  </tr>
		  <tr>
			  <td id="T54"></td>
			  <td id="T55"></td>
			  <td id="T56"></td>
			  <td id="T57"></td>
			  <td id="T58"></td>
			  <td id="T59"></td>
	          <td id="T60"></td>
			  <td id="T61"></td>
			  <td id="T62"></td>
		  </tr>
		  <tr>
			  <td id="T63"></td>
			  <td id="T64"></td>
			  <td id="T65"></td>
			  <td id="T66"></td>
			  <td id="T67"></td>
			  <td id="T68"></td>
			  <td id="T69"></td>
	          <td id="T70"></td>
			  <td id="T71"></td>
		  </tr>
		  <tr>
			  <td id="T72"></td>
			  <td id="T73"></td>
			  <td id="T74"></td>
			  <td id="T75"></td>
			  <td id="T76"></td>
			  <td id="T77"></td>
			  <td id="T78"></td>
			  <td id="T79"></td>
			  <td id="T80"></td>
          </tr>
        </table>
      </td>
      <td class="stats" cellpadding="0" cellspacing="0"> 
        <p>Difficulty: <%=difficulty %></p>
        <p>Problem: <%=option %></p>
        <p>Time Elapsed <span id="minutes"></span>:<span id="seconds"></span></p>	
      </td>
      <td width="30%"></td>
    </tr>
    <tr>
      <td height="60%"> 
	 	<table class="inputBox" cellpadding="0" cellspacing="0">
	 	<tr> <td><input class="inputButton" type="button" value="1" onclick="setValue(this.value)"></td>
	 		<td><input class="inputButton" type="button" value="2" onclick="setValue(this.value)"></td>
	 		<td><input class=inputButton type="button" value="3" onclick="setValue(this.value)"></td>
	 	</tr>
	 	<tr> <td><input class="inputButton" type="button" value="4" onclick="setValue(this.value)"></td>
	 		<td><input class="inputButton" type="button" value="5" onclick="setValue(this.value)"></td>
	 		<td><input class="inputButton" type="button" value="6" onclick="setValue(this.value)"></td>
	 	</tr>
	 	<tr> <td><input class="inputButton" type="button" value="7" onclick="setValue(this.value)"></td>
	 		<td><input class="inputButton" type="button" value="8" onclick="setValue(this.value)"></td>
	 		<td><input class="inputButton" type="button" value="9" onclick="setValue(this.value)"></td>
	 	</tr>	 		 	
	 	</table> 
	   </td>
	   <td> <table class="specialHelp">
		   <tr>
			<td><input class="helpButton" type="button" value="Clear" onclick="clear()"></td>
	 		<td><input class="helpButton" type="button" value="Erase" onclick="erase()"></td>
		   </tr>
		   <tr>
			<td><input class="helpButton" type="button" value="Check" onclick="check()"></td>
	 		<td><input class="helpButton" type="button" value="Pause" onclick="pause()"></td>
		   </tr>
		   <tr>
		   	<td colspan="2">
		   		<input class="helpButton" type="button" value="Submit" disabled onclick=></td>
		   </tr>
	   </table></td>
	 </tr>
	 	
    <tr height="9%">
      <td class="statusCell"> 
      	<input id="find1" class="statusBlock" type="button" value="1" onclick="find(this.value)">
      	<input id="find2" class="statusBlock" type="button" value="2" onclick="find(this.value)">
      	<input id="find3" class="statusBlock" type="button" value="3" onclick="find(this.value)">
      	<input id="find4" class="statusBlock" type="button" value="4" onclick="find(this.value)">
      	<input id="find5" class="statusBlock" type="button" value="5" onclick="find(this.value)">
      	<input id="find6" class="statusBlock" type="button" value="6" onclick="find(this.value)">
      	<input id="find7" class="statusBlock" type="button" value="7" onclick="find(this.value)">
      	<input id="find8" class="statusBlock" type="button" value="8" onclick="find(this.value)">
      	<input id="find9" class="statusBlock" type="button" value="9" onclick="find(this.value)">
      	
      </td>
      <td></td>
      <td></td>
    </tr>
  </table>
  <script>
  	//count clock
	  var sec = 0;
	  function pad ( val ) { return val > 9 ? val : "0" + val; }
	  setInterval( function(){
	      document.getElementById("seconds").innerHTML=pad(++sec%60);
	      document.getElementById("minutes").innerHTML=pad(parseInt(sec/60,10));
	  }, 1000);
 </script>
 <script>
 	 //set table
 	 var className = "";
 	 var problem = "<%=problem%>"

	 for (let i = 0; i < 81; i++) {
		 if (i % 3 == 0) {
			 var col = "y";
		 }
		 else {
			 var col = "n";
		 }
		 if (Math.floor(i / 9) % 3 == 0) {
			 var row = "top";
		 }
		 else {
			 var row = "middle";
		 }
		 var id = i.toString();
		 tcell = document.getElementById("T" + id);
		 className = row + "_" + col;
		 
		 tcell.setAttribute("class", className);
		 tcell.setAttribute("onclick", "onclickTd(this)");
		 tcell.innerHTML = '<input id="I' + id + '" type="button" value=""'
		 + ' onkeypress="return isNumber(this, event)">';
		 
		 tinput = document.getElementById("I" + id);
		 var num = parseInt(problem.charAt(i));
		 
		 if (num == 0) {
			 tinput.setAttribute("maxlength", "1");
			 tinput.setAttribute("class", "nonfilled_inputBox");
		 }
		 
		 else {
			 tcell.setAttribute("class", tcell.getAttribute("class") + " prefilledCell");
			 tinput.setAttribute("class", "prefilled_inputBox");
			 tinput.setAttribute("value", num.toString());
			 tinput.setAttribute("readonly", "");
		 }
	 }
</script>
<script>
		function onclickTd(td) {
			selected = document.getElementById("selected");
			document.getElementById(selected.value).style.background = "";
			deleteblue();
			td.style.background = "rgba(255, 218, 0, 0.6)";
			selected.value = td.id;
		}
		
		function deleteblue() {
			blue = document.getElementById("blue");
			const id = blue.value.split(" ");
			for (let i = 1; i <= id[0]; i++) {
				document.getElementById(id[i]).style.background = "";
			}
			blue.value = "0";
		}
	
	function isNumber(td, evt) {
		if (td.getAttribute("class") == "prefilled_inputBox") {
			return false;
		}
	    evt = (evt) ? evt : window.event;
	    var charCode = (evt.which) ? evt.which : evt.keyCode;
	    if (charCode > 31 && (charCode < 49 || charCode > 57)) {
	        return false;
	    }
	    find_helper((charCode - 48).toString());
	    inputBox = document.getElementById("I" + td.id.substring(1));
	    inputBox.setAttribute("value", (charCode - 48).toString());
	    return true;
	}
	
	function find(number) {
		selected = document.getElementById("selected");
		document.getElementById(selected.value).style.background = "";
		selected.value = "T0"
		find_helper(number);
	}
	
	function find_helper(number) {
		var elements = "";
		var counter = 0;
		blue = document.getElementById("blue");
		if (blue.value != "0") {
			deleteblue();
		}
		for (let i = 0; i < 81; i++) {
			var id = i.toString();
			tinput = document.getElementById("I" + id);
			if (tinput.value == number
					&& ("T" + id) != document.getElementById("selected").value) {
				td = document.getElementById("T" + id);
				td.style.background = "rgba(10, 140, 255, 0.2)";
				elements += " " + td.id;
				counter++;
			}
		}
		elements = counter.toString() + elements;
		blue.value = elements;
	}
	
	function setValue(num) {
		//id = document.getElementById("selected").value.subString(1);
		inputBox = document.getElementById("T1");
		inputBox.value = num;
		
	}
</script>
<script>
	function Clear() {
		
	}
	
	function Erase() {
		
	}
	
	function Check() {
		
	}
	
	function Pause() {
		
	}
	
</script>

</body>
</html>
