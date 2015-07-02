package bit.glennsp1.glennsp1_lab1;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends Activity {

	ListView listView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		listView = (ListView)findViewById(R.id.appSectionList);
		
		Resources res = getResources();
		String[] categories = res.getStringArray(R.array.lab_sections);
		
		ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this,  android.R.layout.simple_list_item_1, categories);
		listView.setAdapter(arrayAdapter);
		
		listView.setOnItemClickListener(onItemClick);
	}

	OnItemClickListener onItemClick = new OnItemClickListener() {

		@Override
		public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
			Intent i;
			
			switch(position) {
				case 0:
					i = new Intent(getBaseContext(), Lab1_Part1.class);
					break;
				case 1:
					i = new Intent(getBaseContext(), Lab1_Part2.class);
					break;
				case 2:
					i = new Intent(getBaseContext(), Lab2_Part1.class);
					break;
				case 3:
					i = new Intent(getBaseContext(), Lab2_Part2.class);
					break;
				default:
					i = null;
					Log.d("Error", "App section selection list case statment has defaulted");
					break;
			}
			
			if(i != null)
				startActivity(i);
		}
	};
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
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
