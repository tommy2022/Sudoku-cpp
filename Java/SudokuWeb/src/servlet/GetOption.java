package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javaCode.Algorithm;

/**
 * Servlet implementation class GetOption
 */
@WebServlet("/Puzzle")
public class GetOption extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public GetOption() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		
	    String view = "/WEB-INF/view/puzzle.jsp";
	    RequestDispatcher dispatcher = request.getRequestDispatcher(view);

	    dispatcher.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String difficulty = request.getParameter("difficulty");
		String option = request.getParameter("option");
		Algorithm sudoku = new Algorithm(difficulty, option);
		String problem = sudoku.getProblem();
		String solution = sudoku.getSolution();
		request.setAttribute("difficulty", difficulty);
		request.setAttribute("option", option);
		request.setAttribute("problem", problem);
		request.setAttribute("solution", solution);
		doGet(request, response);
	}

}
