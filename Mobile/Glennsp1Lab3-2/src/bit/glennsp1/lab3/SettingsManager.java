package bit.glennsp1.lab3;

import android.content.Context;
import android.content.SharedPreferences;

public class SettingsManager {
	
	private static final String PREFRENCES = "PrefsFile";
	private static final String USERNAME_TAG = "USERNAME";
	
	private Context context;
	public SettingsManager(Context context) {
		this.context = context;
	}
	
	public void saveUserName(String username) {
		SharedPreferences.Editor editor = context.getSharedPreferences(PREFRENCES, 0).edit();
		editor.putString(USERNAME_TAG, username);
		editor.commit();
	}
	
	public String getUserName() {
		SharedPreferences settings = context.getSharedPreferences(PREFRENCES, 0);
        String username = settings.getString(USERNAME_TAG, "You have not entered a username yet");
		return username;
	}
}
