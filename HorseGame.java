package unl.cse.horse;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class HorseGame {
    
    private StringBuilder revealedLetters;  // Holds the slowly revealed word
    private String secretWord;      // Random secret word
    
    private int allowedGuesses;     // Number of allowed player guesses
    private int badGuesses;         // Number of incorrect guesses
    private boolean charRevealed;   // Flag if a char has been rightly guessed
    private char guess;             // Variable for player guess
    private boolean won;            // Flag if the player has won
    
    
    /**
     * Starts the game by selecting a random secret word, and tracking player 
     * guesses and invoking methods to display the output.
     * @param wordChoices ArrayList of Strings containing all the possible
     * words to choose a secret one.
     */
    public void startGame( ArrayList<String> wordChoices ){
        
        Scanner askUser = new Scanner( System.in );
        
        /* Prepare to randomly select the secret word */
        Random randomNumber = new Random();
        
        int listSize = wordChoices.size();
        listSize = listSize - 1;    // Adjust for 0 to n-1
        
        /* Generate a random number between 0 and the size of the list-1 */
        int randomIndex = randomNumber.nextInt( listSize );
        
        /* Select the random secret word */
        secretWord = wordChoices.get( randomIndex );
        
        
        /* Prepare the output */
        initializeBlankString( secretWord );
        
        /* Obtain the number of allowed guesses from the user */
        System.out.print( "Please enter the number of allowed guesses: " );
        allowedGuesses = askUser.nextInt();
        
        printWithSpaces();
        
        /* Game loop tracking the number of right and wrong guesses */
        String userGuess;
        do {
            
            System.out.print( "Enter a letter to guess: " );
            userGuess = askUser.next();
            guess = userGuess.charAt( 0 );
            
            charRevealed = revealGuessedLetter( secretWord, guess );
            
            won = checkGuess();
            
            if( !charRevealed )
                badGuesses++;
            
            /* Part of the horse is drawn for each wrong guess */
            drawHorse( badGuesses, allowedGuesses );
            
            printWithSpaces();
                        
        } while ( badGuesses < allowedGuesses && won == false );
        
        if( won ){
            System.out.println( "\nCongratulations!" );
            System.out.println( "You correctly guessed the word: " 
                                                          + secretWord + "!" );
        }
        else{
            System.out.println( "\nSorry, you've run out of guesses." );
            System.out.println( "The correct word was: " + secretWord );
        }        
        
    } // End startGame()
    
    
    /**
     * Sets each char of a StringBuilder equal in length to the secret word to
     * all blank spaces.
     * @param word A String, the secret word being concealed.
     */
    private void initializeBlankString( String word ){
        
        // Initialize the revealedLetters StringBuilder to the secret word 
        // here and set each char to an underscore ( '_' )
		revealedLetters = new StringBuilder(word.length);
		for(int i = 0; i<word.length; i++) {
			revealedLetters.setCharAt(i, '_');
		}
        
    } // End initializeBlankString()
    
    
    /**
     * Prints out the current stage of player progress, showing which letters
     * the player has guessed correctly.
     */
    private void printWithSpaces(){

        System.out.println();
        
        // Write code to print the content of the revealedLetters
        // StringBuilder here, with each letter separated by a space
		for(int i = 0; i<revealedLetters.length; i++) {
			System.out.printf(revealedLetters.substring(i, i+1) + " ");
		}
		
        System.out.println();
        
    } // End printWithSpaces()
    
    
    /**
     * Draws a portion of the horse for each wrong guess that the user makes.  
     * Perhaps not essential, but a neat edition to the program.
     * @param guessedSoFar The number of guesses the user has made.
     * @param allowedGuesses The total number of permitted guesses.
     */
    private void drawHorse( int guessedSoFar, int allowedGuesses ){
        
        String[][] horsey = {
        {"    (\\(\\_\\\0"},
        {" _.o o`\\\\\\\\\0"},
        {"('_     ))))\0"},
        {" '---'  ((((          .=,\0"},
        {"     )   )))___.-''-./=;\\\\\\\0"},
        {"    /    (((         \\  ))))\0"},
        {"   ;                  | |//\0"},
        {"   /\\          |      | ((\0"},
        {"  (  \\    /__.-'\\    /   )\0"},
        {" / /` |  /    \\  \\  |\0"},
        {"/ /   \\ ;      \\ (\\ (\0"},
        {"\\\\_    ||       || ||\0"},
        {" \\_]   ||       || ||\0"},
        {"      /_<      /_</_< \0"} };
        
        
        double ratio = ( (double)guessedSoFar / (double)allowedGuesses );
        int linesToDraw = (int)Math.floor( ratio * 13 );
        linesToDraw = linesToDraw <= 14 ? linesToDraw : 14;
        
        System.out.println();
        for( int i = 14 - linesToDraw; i < 14; i++ ){
            
            System.out.printf( "%s\n", horsey[i] );
        }
        System.out.println();
        
    } // End drawHorse()
    
    
    /**
     * Reveals a correctly guessed letter from the user, while keeping the 
     * rest as blank underscores.
     * @param secret The secret word the user must guess.
     * @param guess The char value guessed by the user.
     * @return True if a guessed letter was revealed, false otherwise.
     */
    private boolean revealGuessedLetter( String secret, char guess ){
        
        boolean found = false;
        
        // Implement this method to alter the revealedLetters StringBuilder.
        // If guess is found to be in the secret word, display that char
        // at each point in revealedLetters by setting it to the appropriate 
        // location(s)
		for(int i = 0; i<secret.length; i++) {
			if(secret(i)==guess) {
				revealedLetters.setCharAt(i, guess);
				found = true;
			}
		}
        
        return found;
        
    } // End revealGuessedLetter()
    
    
    /**
     * Checks if the user has correctly guessed the secret word.
     * @return True if the user has won the game, false otherwise.
     */
    private boolean checkGuess(){
        
        // Implement this method to check if the user has correctly guessed
        // all of the letters in the secret word.  That is, you'll need to
        // compare revealedLetters to secretWord for equality.
		for(int i=0; i<secretWord.length; i++) {
			if(secretWord(i)!=revealedLetters.charAt(i)) {
				return false;
			}
		}

        return true;
        
    }

}
