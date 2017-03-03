public class FireHazard {
	
	public static turnOn() {
		
	}

	public static turnOf() {
		
	}
	
	public static toggle() {
		
	}
	
	
	
	public static void main(String[] args){
		boolean toggle = false
		boolean on = false;
		int startX = 0, startY = 0, stopX = 0, stopY = 0;

		int numberOfLights = 0;
		int x, y;

		String buf, bufArray[], command = null;

		String delim = "[ ,]";

		boolean lightsMatrix[][] = new boolean[1000][1000];
		BufferedReader br = new BufferedReader(new FileReader("day6.txt"));

		while((buf = br.readLine()) != null)
		{   
			bufArray = buf.split(delim);
			if(bufArray[0].equals("toggle"))
			{
				command = "toggle";
				startX = Integer.parseInt(bufArray[1]);
				startY = Integer.parseInt(bufArray[2]);
				stopX = Integer.parseInt(bufArray[4]);
				stopY = Integer.parseInt(bufArray[5]);
			}
			else
			{
				command = bufArray[0] + " " + bufArray[1];
				startX = Integer.parseInt(bufArray[2]);
				startY = Integer.parseInt(bufArray[3]);
				stopX = Integer.parseInt(bufArray[5]);
				stopY = Integer.parseInt(bufArray[6]);
			}

			switch(command)
			{
				case "turn on":
					turnOn = true;
					break;
				case "turn off":
					turnOn = false;
					break;
				case "toggle":
					toggle = true;
					break;
				default:
					System.out.println("Error: command not recognized");
					return;
			}
			for(y = startY; y <= stopY; y++)
			{
				for(x = startX; x <= stopX; x++)
				{
					if(!toggle)
					{
						if(turnOn)
							lightsMatrix[x][y] = true;
						else
							lightsMatrix[x][y] = false;
					}
					else
					{
						toggle = false;
						lightsMatrix[x][y] = !lightsMatrix[x][y];
					}
				}
			}
		}
		
		for(y = 0; y < 1000; y++)
		{
			for(x = 0; x < 1000; x++)
				if(lightsMatrix[x][y])
					numberOfLights++;
		}
		br.close();
	}
}