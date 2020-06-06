<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

    <!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Sudoku</title>
 	<link rel="stylesheet" href ="/SudokuWeb/css/OptionPageStyle.css" />
</head>
<body>
  <header>
    <h1>Welcome to Web Sudoku</h1>
    <h2> What option would you like to play?</h2>
  </header>
  <form method="post" name="form" action="./Puzzle">
  	<input type="hidden" name="difficulty" value=""/>
  	<input type="hidden" name="option" value=""/>
	  <table width="30%">
	    <tr><td>
	      <details>
	        <summary> Easy </summary>
	          <ul>
	            <li> <input type="button" value="Random" onclick="myFunction('Easy', 'Random')"/></li> 
	            <li> <input type="button" value="Problem 1" onclick="myFunction('Easy', 'Problem 1')"/></li>  
	            <li> <input type="button" value="Problem 2" onclick="myFunction('Easy', 'Problem 2')"/></li> 
	          </ul>
	      </details>
	    </td></tr>
	    <tr><td>
	      <details>
	        <summary> Medium </summary>
	        <ul>
	           	<li> <input type="button" value="Random" onclick="myFunction('Medium', 'Random')"/></li> 
	            <li> <input type="button" value="Problem 1" onclick="myFunction('Medium', 'Problem 1')"/></li>  
	            <li> <input type="button" value="Problem 2" onclick="myFunction('Medium', 'Problem 2')"/></li>
	        </ul>
	      </details>
	    </td></tr>
	    <tr><td>
	      <details>
	        <summary> Hard </summary>
	        <ul>
	            <li> <input type="button" value="Random" onclick="myFunction('Hard', 'Random')"/></li> 
	            <li> <input type="button" value="Problem 1" onclick="myFunction('Hard', 'Problem 1')"/></li>  
	            <li> <input type="button" value="Problem 2" onclick="myFunction('Hard', 'Problem 2')"/></li>
	      </details>
	    </td></tr>
	  </table>
  </form>
  <script>
  function myFunction(a, b){

	  if (confirm("Do you want to start puzzle with the following options?\n"
			  + "Difficulty: " + a + "\n"
			  + "Problem Set: " + b)) {  
		  document.form.difficulty.value = a;
		  document.form.option.value = b;
		  document.form.submit();
	  }
	  
  }
  </script>

</body>
</html>
