Models::models[CUBE_MODEL].numVerts = 36;
Models::models[CUBE_MODEL].wiggle = 1.0f;

//front
Models::models[CUBE_MODEL].pos[ 0] = glm::vec3( 1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 1] = glm::vec3( 1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 2] = glm::vec3(-1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 3] = glm::vec3( 1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 4] = glm::vec3(-1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 5] = glm::vec3(-1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].norm[ 0] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].norm[ 1] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].norm[ 2] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].norm[ 3] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].norm[ 4] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].norm[ 5] = glm::vec3(0.0f,0.0f,1.0f);

//right
Models::models[CUBE_MODEL].pos[ 6] = glm::vec3( 1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[ 7] = glm::vec3( 1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[ 8] = glm::vec3( 1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[ 9] = glm::vec3( 1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[10] = glm::vec3( 1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[11] = glm::vec3( 1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].norm[ 6] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[ 7] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[ 8] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[ 9] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[10] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[11] = glm::vec3(1.0f,0.0f,0.0f);

//back
Models::models[CUBE_MODEL].pos[12] = glm::vec3(-1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[13] = glm::vec3(-1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[14] = glm::vec3( 1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[15] = glm::vec3(-1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[16] = glm::vec3( 1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[17] = glm::vec3( 1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].norm[12] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[CUBE_MODEL].norm[13] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[CUBE_MODEL].norm[14] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[CUBE_MODEL].norm[15] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[CUBE_MODEL].norm[16] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[CUBE_MODEL].norm[17] = glm::vec3(0.0f,0.0f,-1.0f);

//left
Models::models[CUBE_MODEL].pos[18] = glm::vec3(-1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[19] = glm::vec3(-1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[20] = glm::vec3(-1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[21] = glm::vec3(-1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[22] = glm::vec3(-1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[23] = glm::vec3(-1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].norm[18] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[19] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[20] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[21] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[22] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].norm[23] = glm::vec3(-1.0f,0.0f,0.0f);

//up
Models::models[CUBE_MODEL].pos[24] = glm::vec3( 1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[25] = glm::vec3( 1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[26] = glm::vec3(-1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[27] = glm::vec3( 1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[28] = glm::vec3(-1.0f, 1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[29] = glm::vec3(-1.0f, 1.0f, 1.0f);
Models::models[CUBE_MODEL].norm[24] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].norm[25] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].norm[26] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].norm[27] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].norm[28] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].norm[29] = glm::vec3(0.0f,1.0f,0.0f);

//down
Models::models[CUBE_MODEL].pos[30] = glm::vec3( 1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[31] = glm::vec3( 1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[32] = glm::vec3(-1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[33] = glm::vec3( 1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].pos[34] = glm::vec3(-1.0f,-1.0f, 1.0f);
Models::models[CUBE_MODEL].pos[35] = glm::vec3(-1.0f,-1.0f,-1.0f);
Models::models[CUBE_MODEL].norm[30] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[CUBE_MODEL].norm[31] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[CUBE_MODEL].norm[32] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[CUBE_MODEL].norm[33] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[CUBE_MODEL].norm[34] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[CUBE_MODEL].norm[35] = glm::vec3(0.0f,-1.0f,0.0f);

Models::models[CUBE_MODEL].color[ 0] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 1] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 2] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 3] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 4] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 5] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[ 6] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[ 7] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[ 8] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[ 9] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[10] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[11] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[12] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[13] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[14] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[15] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[16] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[17] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[CUBE_MODEL].color[18] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[19] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[20] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[21] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[22] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[23] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[CUBE_MODEL].color[24] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[25] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[26] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[27] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[28] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[29] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[CUBE_MODEL].color[30] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[31] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[32] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[33] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[34] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[CUBE_MODEL].color[35] = glm::vec3(1.0f,1.0f,1.0f);

