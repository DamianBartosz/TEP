bool b_dealloc_table_2_dim(int ***piTable, int iSizeX) {
    if (iSizeX < 1 || *piTable == 0) {
        return false;
    }
    for (int i = 0; i < iSizeX; i++) {

        delete[] (*piTable)[i];
    }
    delete[] *piTable;
    return true;
}