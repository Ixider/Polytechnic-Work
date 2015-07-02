package bit.glennsp1.eventful_jsonparsing;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;

public class PrefsManager {

	private static final String PREFS_FILE = "SETTINGS";
	private static final String SEARCH_LOCATION = "LOCATION";
	
	private SharedPreferences prefs;
	
	Context context;
	public PrefsManager(Context context) {
		this.context = context;
		prefs = context.getSharedPreferences(PREFS_FILE, Context.MODE_PRIVATE);
	}
	
	public void saveLocation(String location) {;
		Editor editor = prefs.edit();
		
		editor.putString(SEARCH_LOCATION, location);
		
		editor.commit();
	}
	
	public String getLocation() {
		String location = prefs.getString(SEARCH_LOCATION, null);
		
		return location;
	}
}
