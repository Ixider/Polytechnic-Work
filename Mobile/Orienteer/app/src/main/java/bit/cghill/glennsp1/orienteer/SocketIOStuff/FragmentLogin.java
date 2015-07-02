package bit.cghill.glennsp1.orienteer.SocketIOStuff;

import android.app.Fragment;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.github.nkzawa.emitter.Emitter;
import com.github.nkzawa.socketio.client.Socket;
import com.github.nkzawa.socketio.client.IO;

import org.json.JSONException;
import org.json.JSONObject;

import java.net.URISyntaxException;

import bit.cghill.glennsp1.orienteer.ActivityNavigation;
import bit.cghill.glennsp1.orienteer.R;


/**
 * Created by S. Glenn on 13-May-15.
 */
public class FragmentLogin extends Fragment {

    private static final String sServerUrl = "http://ec2-52-10-104-141.us-west-2.compute.amazonaws.com";


    private Socket mSocket;
    private EditText mUsernameView;
    private String mUsername;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_socket_io_login_layout, container, false);

        init(v);

        return v;
    }

    private void init(View v) {

        mSocket = createSocket();

        mUsernameView = (EditText) v.findViewById(R.id.username_input);
        mUsernameView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView textView, int id, KeyEvent keyEvent) {
                if (id == R.id.login || id == EditorInfo.IME_NULL) {
                    attemptLogin();
                    return true;
                }
                return false;
            }
        });

        Button signInButton = (Button) v.findViewById(R.id.sign_in_button);
        signInButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                attemptLogin();
            }
        });

        mSocket.on("login", onLogin);
    }

    private Socket createSocket() {

        Socket socket = null;
        try {
            socket = IO.socket(sServerUrl);
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }

        return socket;
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        mSocket.off("login", onLogin);
    }

    /**
     * Attempts to sign in the account specified by the login form.
     * If there are form errors (invalid username, missing fields, etc.), the
     * errors are presented and no actual login attempt is made.
     */
    private void attemptLogin() {
        // Reset errors.
        mUsernameView.setError(null);

        // Store values at the time of the login attempt.
        String username = mUsernameView.getText().toString().trim();

        // Check for a valid username.
        if (TextUtils.isEmpty(username)) {
            // There was an error; don't attempt login and focus the first
            // form field with an error.
            mUsernameView.setError("error field id required");
            mUsernameView.requestFocus();
            return;
        }

        mUsername = username;

        // perform the user login attempt.
        mSocket.emit("add user", username);
    }


    private Emitter.Listener onLogin = new Emitter.Listener() {
        @Override
        public void call(Object... args) {
            JSONObject data = (JSONObject) args[0];

            int numUsers;
            try {
                numUsers = data.getInt("numUsers");
            } catch (JSONException e) {
                return;
            }

            Bundle b = new Bundle();
            b.putString("username", mUsername);
            b.putInt("numUsers", numUsers);

            ((ActivityNavigation)getActivity()).userlogedin(b);
        }
    };

}
