package unl.cse.horse;

import java.util.ArrayList;

public class PlayHorse {
    
    public static void main( String[] args ){
        
        /* Prepare to read input from the text file */
        ObtainInput fileInput = new ObtainInput( "data/dictionary.txt" );
        
        /* Obtain input from the external text file */
        ArrayList<String> input;
        input = fileInput.readListOfWords();
        
        /* Start the game */
        HorseGame newGame = new HorseGame();
        newGame.startGame( input );
        
        System.out.println( "\nThanks for playing!" );

    }
    
}
