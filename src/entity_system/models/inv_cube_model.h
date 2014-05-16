Models::models[INV_CUBE_MODEL].numVerts = 36;

//
// INNER SHELL
//

//front
Models::models[INV_CUBE_MODEL].pos[ 0] = glm::vec3( 19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 1] = glm::vec3(-19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 2] = glm::vec3( 19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 3] = glm::vec3( 19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 4] = glm::vec3(-19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 5] = glm::vec3(-19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].norm[ 0] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[ 1] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[ 2] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[ 3] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[ 4] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[ 5] = glm::vec3(0.0f,0.0f,-1.0f);

//right
Models::models[INV_CUBE_MODEL].pos[ 6] = glm::vec3( 19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[ 7] = glm::vec3( 19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[ 8] = glm::vec3( 19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[ 9] = glm::vec3( 19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[10] = glm::vec3( 19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[11] = glm::vec3( 19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].norm[ 6] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[ 7] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[ 8] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[ 9] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[10] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[11] = glm::vec3(-1.0f,0.0f,0.0f);

//back
Models::models[INV_CUBE_MODEL].pos[12] = glm::vec3(-19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[13] = glm::vec3( 19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[14] = glm::vec3(-19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[15] = glm::vec3(-19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[16] = glm::vec3( 19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[17] = glm::vec3( 19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].norm[12] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[13] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[14] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[15] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[16] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[17] = glm::vec3(0.0f,0.0f,1.0f);

//left
Models::models[INV_CUBE_MODEL].pos[18] = glm::vec3(-19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[19] = glm::vec3(-19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[20] = glm::vec3(-19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[21] = glm::vec3(-19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[22] = glm::vec3(-19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[23] = glm::vec3(-19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].norm[18] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[19] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[20] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[21] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[22] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[23] = glm::vec3(1.0f,0.0f,0.0f);

//up
Models::models[INV_CUBE_MODEL].pos[24] = glm::vec3( 19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[25] = glm::vec3(-19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[26] = glm::vec3( 19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[27] = glm::vec3( 19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[28] = glm::vec3(-19.0f, 19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[29] = glm::vec3(-19.0f, 19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].norm[24] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[25] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[26] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[27] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[28] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[29] = glm::vec3(0.0f,-1.0f,0.0f);

//down
Models::models[INV_CUBE_MODEL].pos[30] = glm::vec3( 19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[31] = glm::vec3(-19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[32] = glm::vec3( 19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].pos[33] = glm::vec3( 19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[34] = glm::vec3(-19.0f,-19.0f,-19.0f);
Models::models[INV_CUBE_MODEL].pos[35] = glm::vec3(-19.0f,-19.0f, 19.0f);
Models::models[INV_CUBE_MODEL].norm[30] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[31] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[32] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[33] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[34] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[35] = glm::vec3(0.0f,1.0f,0.0f);

Models::models[INV_CUBE_MODEL].color[ 0] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 1] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 2] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 3] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 4] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 5] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 6] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 7] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 8] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[ 9] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[10] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[11] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[12] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[13] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[14] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[15] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[16] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[17] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[18] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[19] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[20] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[21] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[22] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[23] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[24] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[25] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[26] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[27] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[28] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[29] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[30] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[31] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[32] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[33] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[34] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[35] = glm::vec3(1.0f,1.0f,1.0f);


//
// OUTER SHELL
//

//front
Models::models[INV_CUBE_MODEL].pos[36] = glm::vec3( 21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[37] = glm::vec3( 21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[38] = glm::vec3(-21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[39] = glm::vec3( 21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[40] = glm::vec3(-21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[41] = glm::vec3(-21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].norm[36] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[37] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[38] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[39] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[40] = glm::vec3(0.0f,0.0f,-1.0f);
Models::models[INV_CUBE_MODEL].norm[41] = glm::vec3(0.0f,0.0f,-1.0f);

//right
Models::models[INV_CUBE_MODEL].pos[42] = glm::vec3( 21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[43] = glm::vec3( 21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[44] = glm::vec3( 21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[45] = glm::vec3( 21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[46] = glm::vec3( 21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[47] = glm::vec3( 21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].norm[42] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[43] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[44] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[45] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[46] = glm::vec3(-1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[47] = glm::vec3(-1.0f,0.0f,0.0f);

//back
Models::models[INV_CUBE_MODEL].pos[48] = glm::vec3(-21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[49] = glm::vec3(-21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[50] = glm::vec3( 21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[51] = glm::vec3(-21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[52] = glm::vec3( 21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[53] = glm::vec3( 21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].norm[48] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[49] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[50] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[51] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[52] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].norm[53] = glm::vec3(0.0f,0.0f,1.0f);

//left
Models::models[INV_CUBE_MODEL].pos[54] = glm::vec3(-21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[55] = glm::vec3(-21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[56] = glm::vec3(-21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[57] = glm::vec3(-21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[58] = glm::vec3(-21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[59] = glm::vec3(-21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].norm[54] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[55] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[56] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[57] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[58] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[59] = glm::vec3(1.0f,0.0f,0.0f);

//up
Models::models[INV_CUBE_MODEL].pos[60] = glm::vec3( 21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[61] = glm::vec3( 21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[62] = glm::vec3(-21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[63] = glm::vec3( 21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[64] = glm::vec3(-21.0f, 21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[65] = glm::vec3(-21.0f, 21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].norm[60] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[61] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[62] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[63] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[64] = glm::vec3(0.0f,-1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[65] = glm::vec3(0.0f,-1.0f,0.0f);

//down
Models::models[INV_CUBE_MODEL].pos[66] = glm::vec3( 21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[67] = glm::vec3( 21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[68] = glm::vec3(-21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[69] = glm::vec3( 21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].pos[70] = glm::vec3(-21.0f,-21.0f, 21.0f);
Models::models[INV_CUBE_MODEL].pos[71] = glm::vec3(-21.0f,-21.0f,-21.0f);
Models::models[INV_CUBE_MODEL].norm[66] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[67] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[68] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[69] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[70] = glm::vec3(0.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].norm[71] = glm::vec3(0.0f,1.0f,0.0f);

Models::models[INV_CUBE_MODEL].color[36] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[37] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[38] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[39] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[40] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[41] = glm::vec3(0.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[42] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[43] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[44] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[45] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[46] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[47] = glm::vec3(1.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[48] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[49] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[50] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[51] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[52] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[53] = glm::vec3(1.0f,1.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[54] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[55] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[56] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[57] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[58] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[59] = glm::vec3(1.0f,0.0f,0.0f);
Models::models[INV_CUBE_MODEL].color[60] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[61] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[62] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[63] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[64] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[65] = glm::vec3(0.0f,0.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[66] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[67] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[68] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[69] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[70] = glm::vec3(1.0f,1.0f,1.0f);
Models::models[INV_CUBE_MODEL].color[71] = glm::vec3(1.0f,1.0f,1.0f);

