package bit.glennsp1.lab3;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		Button settingsBtn = (Button)findViewById(R.id.settingsBtn);
		settingsBtn.setOnClickListener(onClick);
		
		setUsername();
	}
	
	OnClickListener onClick = new OnClickListener() {
		@Override
		public void onClick(View v) {
			Intent i = new Intent(getBaseContext(), SettingsActivity.class);
			startActivityForResult(i, 1);
		}	
	};

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		
		setUsername();
	}
	
	private void setUsername() {
		SettingsManager settingsManager = new SettingsManager(getBaseContext());
		String username = settingsManager.getUserName();
		
		TextView usernameDisplay = (TextView)findViewById(R.id.TextView4);
		usernameDisplay.setText(username);
	}
}
