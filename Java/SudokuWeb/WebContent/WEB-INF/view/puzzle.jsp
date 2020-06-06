<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
	<% String difficulty = (String) request.getAttribute("difficulty"); %>
	<% String option = (String) request.getAttribute("option"); %>
	<% String problem = (String) request.getAttribute("option"); %>
	<% String solution = (String) request.getAttribute("option"); %>
<head>
  <meta charset="UTF-8">
  <title>Puzzle_<%=difficulty %>_<%=option %></title>
  <link rel="stylesheet" href ="/SudokuWeb/css/PuzzleStyle.css" />
  <script src="https://kit.fontawesome.com/214bbd63e6.js" crossorigin="anonymous"></script>
</head>
<body>
  <header>
    <h1>Sudoku</h1>
    <a href = "./index.jsp" aria-label = "Home" class='home'><i class="fas fa-home" ></i> </a>
    <hr />
  </header>
  <table class='page' border='1'>
    <tr height="30%">
      <td rowspan="2" width = 50%>
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
			  <td if="T80"></td>
          </tr>
        </table>
      </td>
      <td> 
        <p>Difficulty: <%=difficulty %></p>
        <p>Option: <%=option %></p>
        <p>Time Elapsed <span id="minutes"></span>:<span id="seconds"></span></p>	
      </td>
    </tr>
    <tr height="70%">
      <td> stuffs </td>
    </tr>
    <tr>
      <td> current status displayed here</td>
      <td> submit button goes here</td>
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
 	 var id = "";
 	 var col = "";
 	 var row = "";
 	 var className = "";
 	 var problem = "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"
 	 //var problem = request.getAttribute("problem");
 	 var num = 0;
	 for (let i = 0; i < 81; i++) {
		 if (i % 3 == 0) {
			 col = "y";
		 }
		 else {
			 col = "n";
		 }
		 if (Math.floor(i / 9) % 3 == 0) {
			 row = "top";
		 }
		 else {
			 row = "middle";
		 }
		 id = i.toString();
		 tdata = document.getElementById("T"+id);
		 className = row + "_" + col;
		 
		 tdata.setAttribute("class", className);

		 num = parseInt(problem.charAt(i));
		 
		 if (num == 0) {
			 tdata.setAttribute("maxlength", "1");
		 }
		 
		 else {
			 tdata.setAttribute("readonly", true);
			 tdata.innerHTML = num;
		 }
		 
		 //tdata.innerHTML = 
		 
	 }
 	 
  </script>
</body>
</html>
