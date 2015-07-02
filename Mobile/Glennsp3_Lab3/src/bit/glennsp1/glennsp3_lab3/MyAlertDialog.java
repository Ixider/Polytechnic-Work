package bit.glennsp1.glennsp3_lab3;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.NonNull;


public class MyAlertDialog extends DialogFragment {

	public DialogListener dialogListener;

	public interface DialogListener {
		public void onDialogPositiveClick(DialogFragment dialog);
		public void onDialogNegativeClick(DialogFragment dialog);
	}// End DialogListener

	private String Title; 
	private String Message;
	
	public void setTitle(String Title) { this.Title = Title; }// End setTitle	
	public void setMessage(String Message) { this.Message = Message;
	}// End setMessage

	@Override
	@NonNull
	public Dialog onCreateDialog(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
		
		builder.setTitle(Title);
		builder.setMessage(Message);
		
		builder.setPositiveButton("Ok", onPositiveClickListener);
		builder.setNegativeButton("Cancel", onNegativeClickListener);
		
		return builder.create();
	}// End onCreateDialog
	
	DialogInterface.OnClickListener onPositiveClickListener = new DialogInterface.OnClickListener() {
		@Override
		public void onClick(DialogInterface dialog, int which) {
			dialogListener.onDialogPositiveClick(MyAlertDialog.this);
		}
	};// End onNegativeClickListener
	
	DialogInterface.OnClickListener onNegativeClickListener = new DialogInterface.OnClickListener() {
		@Override
		public void onClick(DialogInterface dialog, int which) {
			dialogListener.onDialogNegativeClick(MyAlertDialog.this);
		}
	};// End onPositiveCLickListener

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		try {
            // Instantiate the NoticeDialogListener so we can send events to the host
            dialogListener = (DialogListener) activity;
        } catch (ClassCastException e) {
            // The activity doesn't implement the interface, throw exception
            throw new ClassCastException(activity.toString()
                    + " must implement DialogListener");
        }
	}// End onAttach

}
