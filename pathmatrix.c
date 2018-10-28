#define INF 99999
struct Graph
{
    int V;
    int E;
    int *Adj;
};
void floydwarshall(struct Graph *G);
void printsolution(struct Graph *G);
void pathmatrix(struct Graph *G);

void floydwarshall(struct Graph *G)
{
    int i,j,k;
    int dist[G->V][G->V];

    for(i=0;i<G->V;i++)
        for(j=0;j<G->V;j++)
            dist[i][j]=*(G->Adj+i*G->V+j);
    for(k=0;k<G->V;k++){
        for(i=0;i<G->V;i++){
            for(j=0;j<G->V;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(i=0;i<G->V;i++)
        for(j=0;j<G->V;j++)
            *(G->Adj+i*G->V+j)=dist[i][j];
}

void printsolution(struct Graph *G)
{
    int i,j;

     for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            if(*(G->Adj+i*G->V+j)==INF)
                printf("%4d",0);
            else
                printf("%4d",*(G->Adj+i*G->V+j));
        }
        printf("\n");
    }
}

void pathmatrix(struct Graph *G)
{
    int i,j,a=1;

     for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            if(*(G->Adj+i*G->V+j)==INF)
                printf("%4d",0);
            else
                printf("%4d",a);
        }
        printf("\n");
    }
}

main()
{
    struct Graph *G;
    int i,j,a,b,c;
    int matrix[4][4];
     G=(struct Graph*)malloc(sizeof(struct Graph));
     G->Adj=malloc(sizeof(int)*(G->V)*(G->V));
     printf("enter value of vertices");
     scanf("%d",&G->V);
    for(b=0;b<G->V;b++)
    {
        for(c=0;c<G->V;c++)
        {
            printf("enter input of [%d][%d]",b,c);
            scanf("%d",&matrix[b][c]);
            if(matrix[b][c]==0)
            {
                matrix[b][c]=INF;
            }
        }
    }

    for(i=0;i<G->V;i++)
        for(j=0;j<G->V;j++)
            *(G->Adj+i*G->V+j)=matrix[i][j];
    printf("original distatnce\n");
    printf("   a   b   c   d\n");
    printsolution(G);
    floydwarshall(G);
    printf("matrix after sortest distance\n");
    printf("   a   b   c   d\n");
    printsolution(G);
    printf("path matricx\n");
    printf("   a   b   c   d\n");
    pathmatrix(G);
}
