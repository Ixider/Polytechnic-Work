package bit.glennsp1.eventful_jsonparsing;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class JsonParser {
	
	public ArrayList<Event> readInputStream(InputStreamReader in) throws IOException, JSONException {
		
		String JSONInput = constructString(new BufferedReader(in));
		JSONObject data = new JSONObject(JSONInput);
		JSONObject events = data.getJSONObject("events");
		JSONArray eventArray = events.getJSONArray("event");
		
		//in.close();
		
		return readEventList(eventArray);
	}
	
	private String constructString(BufferedReader rd) throws IOException {
		String str = "";
		
		String line = "";
		while ((line = rd.readLine()) != null) {
			str += line;
        }
		
		return str;
	}
	
	private ArrayList<Event> readEventList(JSONArray eventArray) throws JSONException {
		ArrayList<Event> events = new ArrayList<Event>();
		
		int arrayLength = eventArray.length();
		for(int i = 0; i < arrayLength; i++) {
			Event e = new Event();
			
			JSONObject currentEvent = eventArray.getJSONObject(i);
			e.Title = currentEvent.getString("title");
			e.Description = currentEvent.getString("description");
			
			events.add(e);
		}
		
		return events;
	}
	
	
}
