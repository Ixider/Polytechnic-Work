package bit.glennsp1.languagetrainer;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class LessonChooser extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lesson_chooser);
        
        ListView lessonList = (ListView)findViewById(R.id.lesssonList);
        lessonList.setOnItemClickListener(onItemClick);
        
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
        														android.R.layout.simple_list_item_activated_1,
    															getResources().getStringArray(R.array.lessonLables));
        
        lessonList.setAdapter(adapter);
    }
    
    OnItemClickListener onItemClick = new OnItemClickListener() {

		@Override
		public void onItemClick(AdapterView<?> parent, View view, int position,
				long id) {
			
			Intent i = new Intent(getBaseContext(), LessonDisplay.class);
			i.putExtra("LessonNumber", position); 
			startActivity(i);	
		}
	};
}
