/**
*A Day In The Life - DEMO VERSION
*Script by I. Coleman and Jacob Rosebaugh; Story and Programming by Jacob Rosebaugh
*(c)2015 Jacob Rosebaugh
*jrosebaugh@huskers.unl.edu
*
*Demonstrates the "jewelry store" scene
*
*/

import java.util.Scanner;
import static java.lang.System.out;
import java.util.Random;


public class Game {

	public static void main(String[] args) {
		boolean white = false;
		boolean black = false;
		boolean male = false;
		boolean female = false;
		boolean tm = false;
		boolean tf = false;
		boolean gay = false;
		boolean str = false;
		int answer;
		char thing;
		
		Scanner s = new Scanner (System.in);
		
		out.println("Welcome to the 'Day in the Life' Before we begin");
		out.println("I have a few questions that I need you to answer.");
		out.println();
		out.println("Are you [1]black or [2]white?");
		
		while(black != true && white != true) {
			answer = s.nextInt();
			if(answer == 1) {
				black = true;
			} else if(answer == 2) {
				white = true;
			} else {
				out.println("Invalid answer.  Are you [1]black or [2]white?");
			}
		}
		answer = 0;
		out.println("What is your gender? [1]Male, [2]Female,");
		out.println("[3]Trans male, or [4]Trans female");
		
		while(answer != 1 && answer != 2 && answer != 3 && answer != 4) {
			answer = s.nextInt();
			if(answer == 1) {
				male = true;
			} else if(answer == 2) {
				female = true;
			} else if(answer == 3) {
				tm = true;
			} else if(answer == 4) {
				tf = true;
			} else {
				out.println("What is your gender? [1]Male, [2]Female,");
				out.println("[3]Trans male, or [4]Trans female");
			}
		}
		
		answer = 0;	
		out.println("Are you [1]gay or [2]straight");
		
		while(gay != true && str != true) {
			answer = s.nextInt();
			if(answer == 1) {
				gay = true;
			} else if(answer == 2) {
				str = true;
			} else {
				out.println("Invalid answer.  Are you [1]gay or [2]straight");
			}
		}
		
		out.println("Good, now we can start you day...");
		out.println();
		out.println("DEMO Version");
		out.println();
		out.println("Your arrive home after your interview feeling");
		if(male == true) {
			out.println ("excited about what happened in the restaurant.");
		} else {
			out.println("conflicted about what happened in the restaurant.");
		}
		out.println("As you change out of your interview clothes, you can't");
		out.println("help but think that you’re forgetting something.  Then");
		out.println("you realize: your mother’s birthday is coming up soon.");
		answer = s.nextInt();
		out.println("You haven’t been able to get her anything for the past couple");
		out.println("of years, but you’ve been saving to get her a new watch that");
		out.println("you know she would like.");
		answer = s.nextInt();
		out.println("You get into your car and head to the jewelry store.");
		answer = s.nextInt();
		
		if(white == true) {
			out.println("You walk into the jewelry store and are immediately");
			out.println("greeted by one of the workers there.");
			answer = s.nextInt();
			out.println("Employee: \"Welcome. Can we help you find anything?\"");
			answer = s.nextInt();
			out.println("You: \"Yes, I'm looking for this watch.\"");
			out.println("You show her a picture of the watch.");
			answer = s.nextInt();
			out.println("Employee: \"Oh my.  That's one of my favorites.  Let me get it.\"");
			out.println("She walks off and comes back a mintue late holding the watch.");
			answer = s.nextInt();
			out.println("You: \"That's the one. I'd like to buy it.\"");
			answer = s.nextInt();
			out.println("Employee: \"Sure thing. Is that everything?\"");
			answer = s.nextInt();
			out.println("You: \"That's it. Do you take checks?\"");
			answer = s.nextInt();
			out.println("Employee: \"Yes we do. Thank you for choosing our store\"");
			answer = s.nextInt();
			out.println("You buy the watch and leave the store.");
		} else {
			out.println("You walk into the jewelry store and an awkward silence");
			out.println("spreads across the store.");
			answer = s.nextInt();
			out.println("Employee: \"Can I help you?\"");
			answer = s.nextInt();
			out.println("You: \"Yes, I'm looking for this watch for my mother.\"");
			out.println("You show her a picture of the watch.");
			answer = s.nextInt();
			out.println("Employee: \"Let me if we have one in stock.\"");
			out.println("She walks off. You notice one of the other employees is watching you.");
			out.println("You turn back and notice a \'We accept checks\' sign hanging on the back");
			out.println("wall. Twenty minutes pass and she walks back out with the watch.");
			answer = s.nextInt();
			out.println("Employee: \"Here it is.\"");
			out.println("She holds out the watch.");
			answer = s.nextInt();
			out.println("You: \"I'd like to buy it.\"");
			answer = s.nextInt();
			out.println("Employee: \"Sure...Is that everything?\"");
			answer = s.nextInt();
			out.println("You: \"Yes. Can I pay with a check?\"");
			answer = s.nextInt();
			out.println("Employee: \"Um, I don't think so because it might bounce...\"");
			answer = s.nextInt();
			out.println("You: \"What do you mean \'might bounce?\'\"");
			answer = s.nextInt();
			out.println("Employee: \"Please calm down. I didn't mean anything by it, We just can't");
			out.println("accept checks. Store policy.\"");
			answer = s.nextInt();
			out.println("You turn and point at the sign.");
			out.println("You: \"But that sign says that you do.\"");
			answer = s.nextInt();
			out.println("Employee: \"We've changed our policy. We haven't taken the sign down yet.\"");
			answer = s.nextInt();
			out.println("You: \"I want to talk to the manager.\"");
			answer = s.nextInt();
			out.println("Employee: \"I am the manager.\"");
			answer = s.nextInt();
			out.println("You: \"Fine, keep your stupid watch.\"");
			answer = s.nextInt();
			out.println("You walk out of the store, forcing yourself to calm down.");
			
		}
		out.println("End of DEMO");
	}
}
