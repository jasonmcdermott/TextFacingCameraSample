#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    font.loadFont("NewMedia Fett.ttf", 24,false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
  
    camera.begin();
    
    ofPushMatrix();
        drawBackground();
        billboardBegin();
        ofSetColor(255);
        ofTranslate(-150, -70);
        font.drawString("I'm looking at camera.", 0, 0);
    ofPopMatrix();
  
    ofPushMatrix();
        ofTranslate(-185, 70);
        font.drawString("I'm not looking at camera.", 0, 0);
    ofPopMatrix();
    
    camera.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::drawBackground(){
    
    int size = 30;
    int step = 30;
    ofSetColor(50);
    
    for(int i = -size/2 ; i < size/2 ; i++){
        for(int j = -size/2 ; j < size/2 ; j++){
            ofPushMatrix();
            ofTranslate(i*step, j*step);
            ofRect(0, 0, 10, 10);
            ofPopMatrix();
        }
    }
}

void testApp::billboardBegin() {

    float modelview[16];
	int i,j;
    
	// save the current modelview matrix
	glPushMatrix();
    
	// get the current modelview matrix
	glGetFloatv(GL_MODELVIEW_MATRIX , modelview);
    
	// undo all rotations
	// beware all scaling is lost as well
	for( i=0; i<3; i++ )
	    for( j=0; j<3; j++ ) {
            if ( i==j )
                modelview[i*4+j] = 1.0;
            else
                modelview[i*4+j] = 0.0;
	    }
    
	// set the modelview with no rotations
	glLoadMatrixf(modelview);
}



void testApp::billboardEnd() {
    
	// restore the previously 
	// stored modelview matrix
	glPopMatrix();
}
