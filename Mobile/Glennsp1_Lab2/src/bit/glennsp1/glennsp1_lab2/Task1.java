package bit.glennsp1.glennsp1_lab2;

import com.example.glennsp1_lab2.R;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;


public class Task1 extends Fragment {
	
	@Override
	public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		View v = inflater.inflate(R.layout.fragment_task1, container, false);
		
		Button button = (Button)v.findViewById(R.id.button1);
		button.setOnClickListener(onClick);
		button.setOnLongClickListener(onLongClick);
		
		return v;
	} // End onCreateView
	
	OnClickListener onClick = new OnClickListener() {
		@Override
		public void onClick(View v) {
			Toast.makeText(getActivity(), "Short Click", Toast.LENGTH_SHORT).show();
		}// End onClick
	}; // End OnClickListener
	
	OnLongClickListener onLongClick = new OnLongClickListener() {
		@Override
		public boolean onLongClick(View v) {
			Toast.makeText(getActivity(), "Long Click", Toast.LENGTH_LONG).show();
			return true;
		}// End onLongClick
	}; // End onLongClickListener

}// End Fragment