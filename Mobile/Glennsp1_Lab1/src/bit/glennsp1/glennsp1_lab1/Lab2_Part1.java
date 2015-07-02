package bit.glennsp1.glennsp1_lab1;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.Button;
import android.widget.Toast;

public class Lab2_Part1 extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lab2__part1);
		
		Button b = (Button)findViewById(R.id.toastButton);
		b.setOnClickListener(onClick);
		b.setOnLongClickListener(onLongClick);
	}
	
	OnClickListener onClick = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			Toast.makeText(getBaseContext(), "Short Press", Toast.LENGTH_SHORT).show();
			
		}
	};
	
	
	OnLongClickListener onLongClick = new OnLongClickListener() {
		
		@Override
		public boolean onLongClick(View v) {
			Toast.makeText(getBaseContext(), "Long Press", Toast.LENGTH_SHORT).show();
			return false;
		}
	};

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.lab2__part1, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
