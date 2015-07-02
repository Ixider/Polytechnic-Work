package bit.glennsp1.lab4_1;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import bit.glennsp1.lab4_1.DataModels.NavItem;

import android.util.JsonReader;

public class JsonParser {
	
	public List readJsonStream(InputStream in) throws IOException {
		JsonReader reader = new JsonReader(new InputStreamReader(in, "UTF-8"));
		try {
		   return readNavItems(reader);
	    }
		finally {
			reader.close();
	    }
	}//End readJsonStream
	
	private List readNavItems(JsonReader reader) throws IOException {
		List<NavItem> navItems = new ArrayList<NavItem>();

		reader.beginArray();
		while (reader.hasNext()) {
			navItems.add(readItem(reader));
		}
		reader.endArray();
		 
		return navItems;
     }//End readNavItems
	
	private NavItem readItem(JsonReader reader) throws IOException {
		 
		 long id = -1;
		 String title = "";
		 String imageName = "";

	     reader.beginObject();
	     while (reader.hasNext()) {
	    	 String name = reader.nextName();
	    	 if (name.equals("id")) {
	    		 id = reader.nextLong();
	    	 } else if (name.equals("title")) {
	    		 title = reader.nextString();
	    	 } else if (name.equals("imageName")) {
	    		 imageName = reader.nextString();
	    	 } else {
	    		 reader.skipValue();
	    	 }
	     }	
	     reader.endObject();
	     
	     return new NavItem(id, title, imageName);
     }//End readItem
	
}//End JsonParser
