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
import android.webkit.WebView.FindListener;
import android.widget.EditText;
import android.widget.Toast;

public class Task3 extends Fragment {
	
	@Override
	public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		View v = inflater.inflate(R.layout.fragment_task3, container, false);
		
		EditText usernameEditText = (EditText)v.findViewById(R.id.usernameEditText);
		usernameEditText.setOnKeyListener(keyListener);
		
		return v;
	}// End onCreateView

	OnKeyListener keyListener = new OnKeyListener() {
		
		@Override
		public boolean onKey(View v, int keyCode, KeyEvent event) {
			
			if(keyCode == KeyEvent.KEYCODE_ENTER && event.getAction() == KeyEvent.ACTION_DOWN) {
				EditText editText = (EditText)getActivity().findViewById(v.getId());
				String username = editText.getText().toString();
				validateUsername(username);
				return true;
			}
			
			return false;
		}// End onKey
	};// End KeyListener

	public void validateUsername(String str) {
		if (str.length() == 8) {
			Toast.makeText(getActivity(), "Thank you, " + str, Toast.LENGTH_LONG).show();
		}
		else {
			Toast.makeText(getActivity(), "Your username must be 8 characters long, " + str, Toast.LENGTH_LONG).show();
		}
	}// End validateUsername
}// End Fragment
