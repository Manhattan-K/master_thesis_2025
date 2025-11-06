function c = pointInsideLoad(q, A, B, D)

    Aq = q - A;
    AB = B - A;
    AD = D - A;
    
    proj_AB = dot(Aq, AB);
    proj_AD = dot(Aq, AD);
    L_AB_sq = dot(AB, AB);
    L_AD_sq = dot(AD, AD);
    
    AB_margin = min(proj_AB, L_AB_sq - proj_AB);
    AD_margin = min(proj_AD, L_AD_sq - proj_AD);
    
    c = min(AB_margin, AD_margin);

end