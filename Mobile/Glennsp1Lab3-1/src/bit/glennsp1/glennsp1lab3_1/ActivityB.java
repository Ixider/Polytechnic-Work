package bit.glennsp1.glennsp1lab3_1;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class ActivityB extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_activity);
		
		configureUI();
	}
	
	private void configureUI() {
		TextView activityLable = (TextView)findViewById(R.id.activityNumberDIsplay);
		activityLable.setText("Activity b");
		
		Button button = (Button)findViewById(R.id.changeBtn);
		button.setOnClickListener(onClickListener);		
	}
	
	OnClickListener onClickListener = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			Uri uri = Uri.parse("http://www.ign.com");
			Intent i = new Intent(Intent.ACTION_VIEW, uri);
			startActivity(i);
		}
	};
}
