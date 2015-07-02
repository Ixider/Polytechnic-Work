package bit.glennsp1.glennsp1_lab2;

import com.example.glennsp1_lab2.R;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnKeyListener;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.Toast;

public class Task2 extends Fragment {

	private EditText textInput;
	
	@Override
	public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.fragment_task2, container,  false);
		
		textInput = (EditText)view.findViewById(R.id.editText);
		textInput.setOnKeyListener(keyListener);
		
		return view;
	}// End onCreateView


	OnKeyListener keyListener = new OnKeyListener() {
		
		@Override
		public boolean onKey(View v, int keyCode, KeyEvent event) {
			
			if(event.getAction() == KeyEvent.ACTION_DOWN) {
				if(keyCode == KeyEvent.KEYCODE_AT) {
					Toast.makeText(getActivity(), "Dont type @", Toast.LENGTH_LONG).show();	
					return true;
				}
			}
			
			return false;
		}// End OnKey
	};// End OnKeyListener
	
}//End Fragment
