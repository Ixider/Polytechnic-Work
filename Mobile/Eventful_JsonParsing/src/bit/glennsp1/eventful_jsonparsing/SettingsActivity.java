package bit.glennsp1.eventful_jsonparsing;

import com.example.eventful_jsonparsing.R;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Button;

public class SettingsActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_settings);
		
		configureUI();
	}//End onCreate
	
	private void configureUI() {
		((Button)findViewById(R.id.settingsSaveButton)).setOnClickListener(onSaveListener);
		
		populateLocationSpinner();
		
		setPositionOfSaveLocation();
	}//End configureUI
	
	// Presents list of locations available to user
	private void populateLocationSpinner() {
		Resources res = getResources();
		
		ArrayAdapter<String> adpater = new ArrayAdapter<String>(this, 
																android.R.layout.simple_dropdown_item_1line,
																res.getStringArray(R.array.locationList));
		
		((Spinner)findViewById(R.id.locationSpinner)).setAdapter(adpater);
	}//End populateLocationSpinner
	
	// Saves the users current location to sharedPrefrences 
	private void saveSettings() {
		PrefsManager settings = new PrefsManager(this);
		
		String location = ((Spinner)findViewById(R.id.locationSpinner)).getSelectedItem().toString();
		
		settings.saveLocation(location);
	}//End saveSettings
	
	private void setPositionOfSaveLocation() {
		String[] locations = getResources().getStringArray(R.array.locationList);
		
		PrefsManager manager = new PrefsManager(this);
		String location = manager.getLocation();
		
		if(!location.equals(null))
			for(int i = 0; i < locations.length; i++) 
				if(locations[i].equals(location))
					((Spinner)findViewById(R.id.locationSpinner)).setSelection(i, true);
		
	}//End getPositionOfSaveLocation
	
	OnClickListener onSaveListener = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			saveSettings();
			finish();
		}
		
	};//End onSaveListener
}//End SettingsACtivity
