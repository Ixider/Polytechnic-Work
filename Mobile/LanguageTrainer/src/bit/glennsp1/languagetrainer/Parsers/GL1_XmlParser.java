package bit.glennsp1.languagetrainer.Parsers;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.util.Xml;
import bit.glennsp1.languagetrainer.Models.LDataModel;

public class GL1_XmlParser {

	public List<LDataModel> parse(InputStream in, int index) throws XmlPullParserException, IOException {
		
		try {
			XmlPullParser parser = Xml.newPullParser();
			parser.setFeature(XmlPullParser.FEATURE_PROCESS_NAMESPACES, false);
            parser.setInput(in, null);
            parser.nextTag();
            return readFeed(parser, index);
			
		} finally {
			in.close();
		}
	}
	
	private List<LDataModel> readFeed(XmlPullParser parser, int index) throws XmlPullParserException, IOException {
	    List<LDataModel> entries = new ArrayList<LDataModel>();

	    parser.require(XmlPullParser.START_TAG, null, "German");
	    
	    while (parser.next() != XmlPullParser.END_TAG) {
	    	   	
	        if (parser.getEventType() != XmlPullParser.START_TAG) {
	            continue;
	        }
	        String name = parser.getName();
	        // Starts by looking for the entry tag
	        String lessonTag = "L" +index +"DATA";
	        if (name.equals(lessonTag)) {
	            entries.add(readEntry(parser, lessonTag));
	        } else {
	            skip(parser);
	        }
	    }  
	    return entries;
	}
	
	private LDataModel readEntry(XmlPullParser parser, String tag) throws XmlPullParserException, IOException {
	    parser.require(XmlPullParser.START_TAG, null, tag);
	    
	    String gender = "";
	    String article = "";
	    String noun = "";
	    String englishTranslation = "";
	    String imageName = "";
	    
	    while (parser.next() != XmlPullParser.END_TAG) {
	        if (parser.getEventType() != XmlPullParser.START_TAG) {
	            continue;
	        }
	        
	        String name = parser.getName();
	      
	        if (name.equals("Gender")) {
	            gender = readGender(parser);
	        } else if (name.equals("Article")) {
	        	article = readArticle(parser);
	        } else if (name.equals("Noun")) { 
	        	noun = readNoun(parser);
	        } else if (name.equals("English")) {
	            englishTranslation = readEnglishTranslation(parser);
	        } else if(name.equals("ImageName")) {
	        	imageName = readImageName(parser);
	        } else {
	            skip(parser);
	        }
	    }
	    
	    return new LDataModel(gender, article, noun, englishTranslation, imageName);
	}
	
	private String readGender(XmlPullParser parser) throws IOException, XmlPullParserException {
	    parser.require(XmlPullParser.START_TAG, null, "Gender");
	    String title = readText(parser);
	    parser.require(XmlPullParser.END_TAG, null, "Gender");
	    return title;
	}
	
	private String readArticle(XmlPullParser parser) throws IOException, XmlPullParserException {
	    parser.require(XmlPullParser.START_TAG, null, "Article");
	    String title = readText(parser);
	    parser.require(XmlPullParser.END_TAG, null, "Article");
	    return title;
	}
	
	private String readNoun(XmlPullParser parser) throws IOException, XmlPullParserException {
	    parser.require(XmlPullParser.START_TAG, null, "Noun");
	    String title = readText(parser);
	    parser.require(XmlPullParser.END_TAG, null, "Noun");
	    return title;
	}
	
	private String readEnglishTranslation(XmlPullParser parser) throws IOException, XmlPullParserException {
	    parser.require(XmlPullParser.START_TAG, null, "English");
	    String title = readText(parser);
	    parser.require(XmlPullParser.END_TAG, null, "English");
	    return title;
	}
	
	private String readImageName(XmlPullParser parser) throws IOException, XmlPullParserException {
	    parser.require(XmlPullParser.START_TAG, null, "ImageName");
	    String title = readText(parser);
	    parser.require(XmlPullParser.END_TAG, null, "ImageName");
	    return title;
	}
	
	// For the tags title and summary, extracts their text values.
	private String readText(XmlPullParser parser) throws IOException, XmlPullParserException {
	    String result = "";
	    if (parser.next() == XmlPullParser.TEXT) {
	        result = parser.getText();
	        parser.nextTag();
	    }
	    return result;
	}
	
	private void skip(XmlPullParser parser) throws XmlPullParserException, IOException {
	    if (parser.getEventType() != XmlPullParser.START_TAG) {
	        throw new IllegalStateException();
	    }
	    int depth = 1;
	    while (depth != 0) {
	        switch (parser.next()) {
	        case XmlPullParser.END_TAG:
	            depth--;
	            break;
	        case XmlPullParser.START_TAG:
	            depth++;
	            break;
	        }
	    }
	 }
}
