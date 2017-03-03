import java.util.Arrays;

public class StringEx {

	public static String renameVar(String name) {
		
		List<String> l = new ArrayList<String>(Arrays.asList(name.split("_")));
		StringBuilder sb = new StringBuilder();
		sb.append(l.remove(0));
		for(String s : l) {
			sb.append(s.toUpperCase)
		}
	}

}