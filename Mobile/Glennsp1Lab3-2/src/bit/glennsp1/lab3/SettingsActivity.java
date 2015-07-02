package bit.glennsp1.lab3;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class SettingsActivity extends Activity {

 
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_settings);
		
		Button saveButton = (Button)findViewById(R.id.saveButton);
		saveButton.setOnClickListener(onSaveClick);
	}
	
	public String getTextEntry() {
		EditText usernameEntry = (EditText)findViewById(R.id.usernameEntry);
		return usernameEntry.getText().toString();
	}
	
	private void saveUserName() {
		SettingsManager settingsManager = new SettingsManager(getBaseContext());
		settingsManager.saveUserName(getTextEntry());
	}
	
	OnClickListener onSaveClick = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			saveUserName();
			setResult(RESULT_OK);
			finish();
		}
	};
}
