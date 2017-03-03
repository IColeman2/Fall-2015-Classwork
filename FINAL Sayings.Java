import java.util.Arrays;

public class SayingsGenerator {
	
	public static String[] getAllCombinations(String adjectives[], String holidays[], String sayings[]) {
		int size = adjectives.length;
		String[] result = new String[Math.pow(size, 3)];
		int resultCounter = 0;
		for(int i = 0; i<size; i++) {
			for(int j = 0; j<size; j++) {
				for(int k = 0; k<size; k++) {
					result[resultCounter] = adjectives[i]+holidays[j]+holidays[k];
					resultCounter++;
				}
			}
		}
		return result;
	}
	
	public static String getHighScore(String combinations[]) {
		int highScore = 0;
		String highScoreString = "";
		for(int i = 0; i<combinations.length; i++) {
			String s = combinations[i];
			boolean repeatedLetters = false;
			int score = 0;
			
			for(int j = 0; j<s.length(); j++) {
				if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'
				   ||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
					   score+=2;
				   }
				else if(s[j]==' ') {
					score-=10;
				}
				else{
					score++;
				}
				
				if(s[j]==' '&&s[1]==s[j+1]) {
					score+=25;
				}
				
				if(s[j]==s[j-1]&&repeatedLetters = false;) {
					score+=15;
					repeatedLetters = true;
				}
			}
			
			if(score>highScore) {
				highScore = score;
				highScoreString = s;
			}
		}
		return highScoreString;
		
	}
	
	public static void main(String[] args){
		String[] adjectives = {"Happy", "Joyful", "Risible", "Merry", "Crazy", "Joyous", "Cromulent", "Somber"};
		String[] holidays = {"Christmas", "Hanukkah", "Noel", "Holidays", "Life Day", "Festivus", "Kwanzaa", "Chrimbus"};
		String[] sayings = {"to all and to all agood night!", "for your hair!", "and may the Force be with you!", "for the rest of us!", "mazel tov!", "and God bless us veeryone!", "and a happy new year!", "great job!"};

		String[] combinations = getAllCombinations(adjectives, holidays, sayings);
		String result = getHighScore(combinations);
		System.out.printf("%s", result);
	}
}