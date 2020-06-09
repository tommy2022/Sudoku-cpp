package javaCode;

public class Algorithm {
	private String problem;
	private String solution;
	private String E1_Q = "001000700290150083604002000029005876040"
					+ "001305005897000953718624012643000476009138";
	private String E1_S = "531984762297156483684372519129435876748"
					+ "261395365897241953718624812643957476529138";
	private String H1_Q = "900000000820000700000050040070009000001"
					+ "008000005000130000007008003010000000000000";
	private String H1_S = "954782613826341795137956842472139586391"
					+ "568427685274139519427368263815974748693251";
	
	public Algorithm(String difficulty, String option) {
		if (difficulty.equals("Easy") && option.equals("Problem 1")) {
			problem = E1_Q;
			solution = E1_S;
		}
		else if (difficulty.equals("Hard") && option.equals("Problem 1")) {
			problem = H1_Q;
			solution = H1_S;
		}
		
	}
	
	public String getProblem() {
		return problem;
	}
	
	public String getSolution() {
		return solution;
	}
}
