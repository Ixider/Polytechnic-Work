package bit.glennsp1.languagetrainer;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;

public class ResultDialog extends DialogFragment {
	String title;
	String message;
	
	ResultDialogListener mListener;
	
	public ResultDialog(String title, String message) {
		this.title = title;
		this.message = message;
	} 
	
	public interface ResultDialogListener {
	    public void onResultDialogPositiveClick(DialogFragment dialog);
	}
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setTitle(title)
        	.setMessage(message)
               .setPositiveButton("Continue", new DialogInterface.OnClickListener() {   
                   public void onClick(DialogInterface dialog, int id) { 
                	   mListener.onResultDialogPositiveClick(ResultDialog.this);
                   }
               });
        // Create the AlertDialog object and return it
        return builder.create();
    }// End onCreateDialog
    
	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		try {
            // Instantiate the NoticeDialogListener so we can send events to the host
            mListener = (ResultDialogListener) activity;
        } catch (ClassCastException e) {
            // The activity doesn't implement the interface, throw exception
            throw new ClassCastException(activity.toString()
                    + " must implement ConfirmationDialogListener");
        }
    }// End onAttach
}